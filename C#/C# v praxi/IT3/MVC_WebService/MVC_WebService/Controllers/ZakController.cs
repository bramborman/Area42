using MVC_WebService.Models;
using MVC_WebService.SkolaWS;
using System;
using System.Collections.Generic;
using System.Web.Mvc;

namespace MVC_WebService.Controllers
{
    public class ZakController : Controller
    {
        // GET: Zak
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult List()
        {
            SkolaSoapClient skola = new SkolaSoapClient();
            List<ZakModel> seznamZaku = new List<ZakModel>();

            foreach (SkolaZaci skolaZaci in skola.ZaciList())
            {
                seznamZaku.Add(new ZakModel
                {
                    Id          = skolaZaci.Id,
                    Jmeno       = skolaZaci.Jmeno,
                    Prijmeni    = skolaZaci.Prijmeni,
                    Muz         = skolaZaci.Muz,
                    RodneCislo  = skolaZaci.RodneCislo,
                    Studuje     = skolaZaci.Studuje,
                    Trida       = skolaZaci.Trida,
                    ZmenenoKdy  = skolaZaci.ZmenenoKdy,
                    ZmenenoKdo  = skolaZaci.ZmenenoKdo
                });
            }

            ViewBag.PocetZaku = seznamZaku.Count;
            return View(seznamZaku);
        }

        [HttpGet]
        public ActionResult Create()
        {
            return View(new ZakModel
            {
                ZmenenoKdo  = "(⌐■_■)"
            });
        }

        [HttpPost]
        public ActionResult Create(ZakModel zak)
        {
            new SkolaSoapClient().ZaciCreate(new SkolaZaci
            {
                Id          = Guid.NewGuid(),
                Jmeno       = zak.Jmeno,
                Prijmeni    = zak.Prijmeni,
                Muz         = zak.Muz,
                RodneCislo  = zak.RodneCislo,
                Studuje     = zak.Studuje,
                Trida       = Guid.NewGuid(),
                ZmenenoKdy  = DateTime.Now,
                ZmenenoKdo  = zak.ZmenenoKdo
            });

            return View(zak);
        }

        public ActionResult Delete(string id)
        {
            new SkolaSoapClient().ZaciSmazat(id);
            return RedirectToAction("List");
        }
    }
}