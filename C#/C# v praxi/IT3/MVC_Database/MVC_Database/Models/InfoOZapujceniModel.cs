using System;
using System.ComponentModel;
using System.Configuration;

namespace MVC_Database.Models
{
    public sealed class InfoOZapujceniModel
    {
        private static readonly int maximalniVypujcniDobaVeDnech = int.Parse(ConfigurationManager.AppSettings["MaximalniVypujcniDobaVeDnech"]);

        public int Id { get; set; }
        public int KnihovnaID { get; set; }
        [DisplayName("JMÉNO ŽÁKA")]
        public int SkolaZaciID { get; set; }
        [DisplayName("DATUM ZAPŮJČENÍ")]
        public DateTime DatumZapujceni { get; set; }
        public DateTime? DatumVraceni { get; set; }

        public Knihovna Knihovna { get; set; }
        public SkolaZaci SkolaZaci { get; set; }
        
        [DisplayName("PŘEKROČENA MAXIMÁLNÍ VÝPUJČNÍ DOBA")]
        public bool JePrekrocenaMaximalniVypujcniDobaVeDnech
        {
            get
            {
                return DatumVraceni == null && (DateTime.Now - DatumZapujceni).Days > maximalniVypujcniDobaVeDnech;
            }
        }
        [DisplayName("DATUM VRÁCENÍ")]
        public string DatumVraceniString
        {
            get
            {
                return DatumVraceni?.ToString() ?? "Dosud vypůjčeno";
            }
        }
        [DisplayName("KNIHA")]
        public string Kniha
        {
            get
            {
                return $"{Knihovna.Autor} - {Knihovna.Nazev}";
            }
        }

        public static implicit operator InfoOZapujceniModel(InfoOZapujceni i)
        {
            return new InfoOZapujceniModel
            {
                Id              = i.Id,
                KnihovnaID      = i.KnihovnaID,
                SkolaZaciID     = i.SkolaZaciID,
                DatumZapujceni  = i.DatumZapujceni,
                DatumVraceni    = i.DatumVraceni,
                Knihovna        = i.Knihovna,
                SkolaZaci       = i.SkolaZaci
            };
        }

        public static implicit operator InfoOZapujceni(InfoOZapujceniModel i)
        {
            return new InfoOZapujceni
            {
                Id              = i.Id,
                KnihovnaID      = i.KnihovnaID,
                SkolaZaciID     = i.SkolaZaciID,
                DatumZapujceni  = i.DatumZapujceni,
                DatumVraceni    = i.DatumVraceni,
                Knihovna        = i.Knihovna,
                SkolaZaci       = i.SkolaZaci
            };
        }
    }
}