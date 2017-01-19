using System;
using System.ComponentModel;

namespace MVC_WebService.Models
{
    public class TridaModel
    {
        public Guid Id { get; set; }
        [DisplayName("NÁZEV")]
        public string Nazev { get; set; }
        [DisplayName("TŘÍDNÍ")]
        public string Tridni { get; set; }
        [DisplayName("ZMĚNĚNO KDY")]
        public DateTime ZmenenoKdy { get; set; }
        [DisplayName("ZMĚNENO KDO")]
        public string ZmenenoKdo { get; set; }
        [DisplayName("ROČNÍK")]
        public int? Rocnik { get; set; }
        [DisplayName("ULOŽENO")]
        public bool Ulozeno { get; set; }
    }
}