using System;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace MVC_Database.Models
{
    public sealed class SkolaZaciModel
    {
        public int Id { get; set; }

        [DisplayName("JMÉNO")]
        [Required]
        public string Jmeno { get; set; }

        [DisplayName("PŘÍJMENÍ")]
        [Required]
        public string Prijmeni { get; set; }

        [DisplayName("RODNÉ ČÍSLO")]
        [Required]
        public string RodneCislo { get; set; }

        [DisplayName("JE MUŽ")]
        public bool? JeMuz { get; set; }

        [DisplayName("TŘÍDA")]
        [Required]
        public string Trida { get; set; }

        [DisplayName("STUDUJE")]
        public bool? Studuje { get; set; }

        [DisplayName("DATUM ZMĚNY")]
        public DateTime DatumZmeny { get; set; }

        [DisplayName("AUTOR ZMĚNY")]
        [Required]
        public string AutorZmeny { get; set; }

        public static implicit operator SkolaZaciModel(SkolaZaci z)
        {
            return new SkolaZaciModel
            {
                Id          = z.Id,
                Jmeno       = z.Jmeno,
                Prijmeni    = z.Prijmeni,
                RodneCislo  = z.RodneCislo,
                JeMuz       = z.JeMuz,
                Trida       = z.Trida,
                Studuje     = z.Studuje,
                DatumZmeny  = z.DatumZmeny,
                AutorZmeny  = z.AutorZmeny
            };
        }

        public static implicit operator SkolaZaci(SkolaZaciModel z)
        {
            return new SkolaZaci
            {
                Id          = z.Id,
                Jmeno       = z.Jmeno,
                Prijmeni    = z.Prijmeni,
                RodneCislo  = z.RodneCislo,
                JeMuz       = z.JeMuz,
                Trida       = z.Trida,
                Studuje     = z.Studuje,
                DatumZmeny  = z.DatumZmeny,
                AutorZmeny  = z.AutorZmeny
            };
        }
    }
}