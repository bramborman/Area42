using MVC_Database.AppCode.DB;
using MVC_Database.Models;
using System.Linq;
using System.Web.Mvc;

namespace MVC_Database.Controllers
{
    public class KnihovnaController : Controller
    {
        public ActionResult KnihyZaka(int idZaka)
        {
            ViewBag.IdZaka = idZaka;
            return View(new KnihovnaTableController().GetAllOnZak(idZaka).Select(knihovna => (KnihovnaModel)knihovna));
        }
        
        public ActionResult PujcitKnihu(int idZaka)
        {
            ViewBag.IdZaka = idZaka;
            return View(new KnihovnaTableController().GetAllNepujcene().Select(knihovna => (KnihovnaModel)knihovna));
        }
        
        public ActionResult PujcitKnihuZakovi(int idKnihy, int idZaka)
        {
            new KnihovnaTableController().PujcitKnihuZakovi(idKnihy, idZaka);
            return RedirectToAction("Index", "Zaci");
        }

        public ActionResult VratitKnihuOdZaka(int idKnihy, int idZaka)
        {
            new KnihovnaTableController().VratitKnihuOdZaka(idKnihy, idZaka);
            return RedirectToAction("Index", "Zaci");
        }
    }
}