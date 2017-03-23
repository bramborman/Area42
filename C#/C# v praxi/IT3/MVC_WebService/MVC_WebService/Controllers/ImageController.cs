using MVC_WebService.SkolaWS;
using System.Web.Mvc;

namespace MVC_WebService.Controllers
{
    public class ImageController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }
        
        [HttpGet]
        public ActionResult GetImage(int id)
        {
            try
            {
                Soubory soubor = new SkolaSoapClient().SouborGet(id);
                string nazev = soubor.nazev.ToLower();
                string mimeType = "image/";

                if (nazev.EndsWith(".jpg") || nazev.EndsWith(".jpeg"))
                {
                    mimeType += "jpeg";
                }
                else if (nazev.EndsWith(".png"))
                {
                    mimeType += "png";
                }

                return File(soubor.data, mimeType);
            }
            catch
            {
                return null;
            }
        }
    }
}