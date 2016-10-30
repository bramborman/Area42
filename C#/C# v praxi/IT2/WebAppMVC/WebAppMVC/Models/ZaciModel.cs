using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebAppMVC.Models
{
    public class ZaciModel
    {
        public int ID { get; set; }

        [Display(Name = "Jméno")]
        [Required(ErrorMessage = "Nutno zadat jméno")]
        [StringLength(60)]
        public string Jmeno { get; set; }

        [Display(Name = "Příjmení")]
        [Required(ErrorMessage = "Nutno zadat příjmení")]
        [StringLength(60)]
        public string Prijmeni { get; set; }

        [Display(Name = "Muž")]
        [Required(ErrorMessage = "Nutno zadat pohlaví")]
        public bool JeMuz { get; set; }

        [Display(Name = "Třída")]
        [Required(ErrorMessage = "Nutno zadat třídu")]
        [StringLength(60)]
        public string Trida { get; set; }
    }
}