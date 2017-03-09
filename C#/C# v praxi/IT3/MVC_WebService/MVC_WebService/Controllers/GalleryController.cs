using MVC_WebService.Models;
using MVC_WebService.SkolaWS;
using System.Collections.Generic;
using System.Linq;
using System.Web.Mvc;

namespace MVC_WebService.Controllers
{
    public class GalleryController : Controller
    {
        private const string SESSION_GALLERY = "GalleryCache";

        public ActionResult Index()
        {
            Soubory[] soubory = new SkolaSoapClient().SouborGetList();

            if (Session[SESSION_GALLERY] == null)
            {
                Session.Add(SESSION_GALLERY, soubory);
            }
            else
            {
                Session[SESSION_GALLERY] = soubory;
            }

            List<SouboryModel> souboryOutput = new List<SouboryModel>(soubory.Length);

            foreach (Soubory soubor in soubory)
            {
                souboryOutput.Add(new SouboryModel
                {
                    Id      = soubor.Id,
                    Nazev   = soubor.nazev,
                    Popis   = soubor.popis
                });
            }

            return View(souboryOutput);
        }

        [HttpGet]
        public ActionResult Image(int id, bool miniature)
        {
            Soubory[] soubory = Session[SESSION_GALLERY] as Soubory[];

            if (soubory == null)
            {
                return null;
            }

            byte[] data;

            if (miniature)
            {
                data = new SkolaSoapClient().SouborGetMiniatura(id);
            }
            else
            {
                data = new SkolaSoapClient().SouborGet(id).data;
            }

            Soubory soubor  = soubory.FirstOrDefault(s => s.Id == id);

            if (soubor == null)
            {
                return null;
            }

            string nazev    = soubor.nazev.ToLower();
            string mimeType = "image/";

            if (nazev.EndsWith(".jpg") || nazev.EndsWith(".jpeg"))
            {
                mimeType += "jpeg";
            }
            else if (nazev.EndsWith(".png"))
            {
                mimeType += "png";
            }

            return File(data, mimeType);
        }
    }
}