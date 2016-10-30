using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WebAppMVC_eshop.Models
{
    public class KosikModel
    {
        public Guid IdUzivatele { get; set; }

        public Dictionary<Guid,int> PolozkyVKosiku { get; set; }

        public KosikModel()
        {
            PolozkyVKosiku = new Dictionary<Guid, int>();
            IdUzivatele = Guid.NewGuid();
        }
    }
}