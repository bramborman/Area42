using NotifyPropertyChangedBase;
using System.IO;
using System.Text;

namespace TAG
{
    public sealed class TextFontDefinition : NotifyPropertyChanged
    {
        public const uint VERSION = 0;

        private static readonly Encoding encoding = Encoding.UTF8;

        public uint Version
        {
            get { return (uint)GetValue(); }
            private set { SetValue(value); }
        }
        public string Name
        {
            get { return (string)GetValue(); }
            set { SetValue(value); }
        }
        public uint CharWidth
        {
            get { return (uint)GetValue(); }
            set { SetValue(value); }
        }
        public uint CharHeight
        {
            get { return (uint)GetValue(); }
            set { SetValue(value); }
        }
        public bool Resizeable
        {
            get { return (bool)GetValue(); }
            set { SetValue(value); }
        }

        public TextFontDefinition(uint version = VERSION)
        {
            RegisterProperty(nameof(Version), typeof(uint), version);
            RegisterProperty(nameof(Name), typeof(string), null);
            RegisterProperty(nameof(CharWidth), typeof(uint), 1u);
            RegisterProperty(nameof(CharHeight), typeof(uint), 1u);
            RegisterProperty(nameof(Resizeable), typeof(bool), false);
        }

        public void SaveToFile(string path)
        {
            using (FileStream stream = File.OpenWrite(path))
            {
                using (BinaryWriter writer = new BinaryWriter(stream, encoding))
                {
                    Version = VERSION;

                    writer.Write(Version);
                    writer.Write(Name);
                    writer.Write(CharWidth);
                    writer.Write(CharHeight);
                    writer.Write(Resizeable);
                }
            }
        }

        public static TextFontDefinition ReadFromFile(string path)
        {
            using (FileStream stream = File.OpenRead(path))
            {
                using (BinaryReader reader = new BinaryReader(stream, encoding))
                {
                    return new TextFontDefinition(reader.ReadUInt32())
                    {
                        Name            = reader.ReadString(),
                        CharWidth       = reader.ReadUInt32(),
                        CharHeight      = reader.ReadUInt32(),
                        Resizeable      = reader.ReadBoolean()
                    };
                }
            }
        }
    }
}
