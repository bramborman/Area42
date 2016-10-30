using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebAppMVC_eshop.Models;

namespace WebAppMVC_eshop.Controllers
{
    public class ZboziController : Controller
    {
        // GET: Zbozi
        public ActionResult Index()
        {
            return RedirectToAction("Seznam");
        }

        public ActionResult Seznam()
        {
            int pocetKusu = 0;
            decimal cenaCelkem = 0, prumer = 0;

            foreach (ZboziModel item in MainData.DatabazeZbozi)
            {
                pocetKusu += item.PocetKusuNaSklade;
                cenaCelkem += item.Cena;

                prumer += item.Cena;
            }

            ViewBag.PocetKusu = pocetKusu;
            ViewBag.CenaCelkem = cenaCelkem;

            if (pocetKusu != 0)
            {
                ViewBag.Prumer = prumer / pocetKusu;
            }

            return View(MainData.DatabazeZbozi);
        }

        public ActionResult Create(ZboziModel zbozi)
        {
            if (zbozi.PocetKusuNaSklade < 0)
            {
                ViewBag.Cancer = "Málo toho máš";
                return View(zbozi);
            }

            if (!ModelState.IsValid)
            {
                ViewBag.Cancer = "Nefunguje ti to";
                return View(zbozi);
            }

            zbozi.ID = Guid.NewGuid();

            MainData.DatabazeZbozi.Add(zbozi);
            
            ViewBag.Cancer = "fiša";

            return View(zbozi);
        }

        [HttpGet]
        public ActionResult Edit(Guid id)
        {
            ZboziModel zboziKEditaci = MainData.DatabazeZbozi.Where(d => d.ID == id).FirstOrDefault();

            return View(zboziKEditaci);
        }

        [HttpPost]
        public ActionResult Edit(ZboziModel zbozi)
        {
            ZboziModel zboziKEditaci = MainData.DatabazeZbozi.Where(d => d.ID == zbozi.ID).FirstOrDefault();
            zboziKEditaci.Cena = zbozi.Cena;
            zboziKEditaci.Nazev = zbozi.Nazev;
            zboziKEditaci.PocetKusuNaSklade = zbozi.PocetKusuNaSklade;
            zboziKEditaci.Popis = zbozi.Popis;

            return View(zbozi);
        }

        public ActionResult Delete(Guid id)
        {
            ZboziModel zboziKeSmazani = MainData.DatabazeZbozi.Where(d => d.ID == id).FirstOrDefault();
            MainData.DatabazeZbozi.Remove(zboziKeSmazani);

            return RedirectToAction("Seznam");
        }
    }
}