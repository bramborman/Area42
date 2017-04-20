using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace MVC_Database.Models
{
    public sealed class KnihovnaModel
    {
        public int Id { get; set; }
        [DisplayName("NÁZEV")]
        [Required]
        public string Nazev { get; set; }
        public int? ZapujcenoID { get; set; }
        [DisplayName("AUTOR")]
        public string Autor { get; set; }

        public SkolaZaci SkolaZaci { get; set; }

        public static implicit operator KnihovnaModel(Knihovna k)
        {
            return new KnihovnaModel
            {
                Id          = k.Id,
                Nazev       = k.Nazev,
                ZapujcenoID = k.ZapujcenoID,
                Autor       = k.Autor,
                SkolaZaci   = k.SkolaZaci
            };
        }

        public static implicit operator Knihovna(KnihovnaModel k)
        {
            return new Knihovna
            {
                Id          = k.Id,
                Nazev       = k.Nazev,
                ZapujcenoID = k.ZapujcenoID,
                Autor       = k.Autor,
                SkolaZaci   = k.SkolaZaci
            };
        }
    }
}