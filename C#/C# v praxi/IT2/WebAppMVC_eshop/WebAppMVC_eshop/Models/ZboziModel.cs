using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebAppMVC_eshop.Models
{
    public class ZboziModel
    {
        public Guid ID { get; set; }

        [Display(Name = "Název")]
        [Required]
        public string Nazev { get; set; }

        [Required]
        public string Popis { get; set; }

        [Display(Name = "Počet kusů na skladě")]
        [Required]
        [Range(0, 100000)]
        public int PocetKusuNaSklade { get; set; }

        /// <summary>
        /// bez DPH
        /// </summary>
        [Required]
        [Range(1, 100000)]
        public decimal Cena { get; set; }
    }
}