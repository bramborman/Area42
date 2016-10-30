using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebAppMVC.Models;

namespace WebAppMVC.Controllers
{
    public class ZaciController : Controller
    {
        public static List<ZaciModel> zaci;

        public ZaciController()
        {
            if (zaci == null)
            {
                zaci = VytvorZaky();
            }
        }

        // GET: Zaci
        public ActionResult Index()
        {
            return RedirectToAction("SeznamZaku");
        }

        public ActionResult SeznamZaku()
        {
            return View(zaci);
        }

        [HttpGet]
        public ActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Create(ZaciModel zak)
        {
            zaci.Add(zak);
            return RedirectToAction("SeznamZaku");
        }

        private List<ZaciModel> VytvorZaky()
        {
            List<ZaciModel> zaci = new List<ZaciModel>();

            ZaciModel zak = new ZaciModel();

            zak.ID = 1;
            zak.Jmeno = "Martin";
            zak.Prijmeni = "Fiša";
            zak.Trida = "Tulipán";
            zak.JeMuz = false;

            zaci.Add(zak);

            ZaciModel zak2 = new ZaciModel();

            zak2.ID = 2;
            zak2.Jmeno = "Tulipán";
            zak2.Prijmeni = "Martin";
            zak2.Trida = "Fiša";
            zak2.JeMuz = true;

            zaci.Add(zak2);

            return zaci;
        }
    }
}