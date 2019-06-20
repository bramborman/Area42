using System;
using System.Runtime.Serialization;

namespace StorageTools.Helpers
{
    [Serializable]
    public sealed class ConsoleArgumentException : Exception
    {
        public string ArgumentName { get; }
        public ArgumentExceptionType Type { get; }

        public ConsoleArgumentException(string argumentName, ArgumentExceptionType type) : this(argumentName, type, null)
        {

        }

        public ConsoleArgumentException(string argumentName, ArgumentExceptionType type, Exception innerException) : base(null, innerException)
        {
            ArgumentName = argumentName;
            Type = type;
        }

        private ConsoleArgumentException(SerializationInfo info, StreamingContext context) : base(info, context)
        {

        }


        public enum ArgumentExceptionType
        {
            InvalidName,
            MissingData,
            InvalidData
        }
    }
}
