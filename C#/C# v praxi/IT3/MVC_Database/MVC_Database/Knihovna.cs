//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace MVC_Database
{
    using System;
    using System.Collections.Generic;
    
    public partial class Knihovna
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Knihovna()
        {
            this.InfoOZapujceni = new HashSet<InfoOZapujceni>();
        }
    
        public int Id { get; set; }
        public string Nazev { get; set; }
        public Nullable<int> ZapujcenoID { get; set; }
        public string Autor { get; set; }
    
        public virtual SkolaZaci SkolaZaci { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<InfoOZapujceni> InfoOZapujceni { get; set; }
    }
}
