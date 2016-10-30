using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WebAppMVC_2.Models
{
    public class ImageModel
    {
        public int ID { get; set; }

        public string FileName { get; set; }

        public string FileLocationDisc { get; set; }

        public string FileLocationWeb { get; set; }
    }
}