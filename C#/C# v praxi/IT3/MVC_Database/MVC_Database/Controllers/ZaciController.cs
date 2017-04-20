using MVC_Database.AppCode.DB;
using MVC_Database.Models;
using System;
using System.Linq;
using System.Web.Mvc;

namespace MVC_Database.Controllers
{
    public class ZaciController : Controller
    {
        public ActionResult Index()
        {
            SkolaZaciTableController controller = new SkolaZaciTableController();
            return View(controller.GetAll().Select(skolaZaci => (SkolaZaciModel)skolaZaci));
        }

        public ActionResult ZakPrijmeni()
        {
            return View(new SkolaZaciTableController().GetZaciWithPrijmeni("Gnymors"));
        }

        [HttpGet]
        public ActionResult AddZak()
        {
            return View(new SkolaZaciModel
            {
                DatumZmeny = DateTime.Now
            });
        }

        [HttpPost]
        public ActionResult AddZak(SkolaZaciModel zak)
        {
            new SkolaZaciTableController().AddZak(zak);
            return View(zak);
        }

        public ActionResult DeleteZak(int id)
        {
            new SkolaZaciTableController().DeleteZak(id);
            return RedirectToAction("Index");
        }
    }
}