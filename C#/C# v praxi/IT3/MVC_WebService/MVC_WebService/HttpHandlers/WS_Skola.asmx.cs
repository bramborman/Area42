using MVC_WebService.Models;
using MVC_WebService.SkolaWS;
using System.Collections.Generic;
using System.Web.Services;

namespace MVC_WebService.HttpHandlers
{
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class WS_Skola : WebService
    {
        [WebMethod]
        public string HelloWorld()
        {
            return "Hello World";
        }

        [WebMethod]
        public List<TridaModel> GetTridaModels()
        {
            List<TridaModel> output = new List<TridaModel>();

            foreach (SkolaTridy skolaTridy in new SkolaSoapClient().TridaList())
            {
                output.Add(new TridaModel
                {
                    Id          = skolaTridy.Id,
                    Nazev       = skolaTridy.Nazev,
                    Tridni      = skolaTridy.Tridni,
                    ZmenenoKdy  = skolaTridy.ZmenenoKdy,
                    ZmenenoKdo  = skolaTridy.ZmenenoKdo,
                    Rocnik      = skolaTridy.Rocnik,
                });
            }

            return output;
        }

        [WebMethod]
        public int Addition(int x, int y)
        {
            return x + y;
        }
    }
}
