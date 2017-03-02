using MVC_WebService.Models;
using MVC_WebService.SkolaWS;
using System;
using System.Collections.Generic;
using System.Web.Mvc;

namespace MVC_WebService.Controllers
{
    public class TridaController : Controller
    {
        public ActionResult List()
        {
            SkolaWS.SkolaSoapClient skola = new SkolaWS.SkolaSoapClient();
            List<TridaModel> seznamTrid = new List<TridaModel>();

            foreach (SkolaTridy skolaTridy in skola.TridaList())
            {
                TridaModel trida = new TridaModel
                {
                    Id          = skolaTridy.Id,
                    Nazev       = skolaTridy.Nazev,
                    Tridni      = skolaTridy.Tridni,
                    ZmenenoKdy  = skolaTridy.ZmenenoKdy,
                    ZmenenoKdo  = skolaTridy.ZmenenoKdo,
                    Rocnik      = skolaTridy.Rocnik,
                };

                seznamTrid.Add(trida);
            }

            ViewBag.PocetTrid = seznamTrid.Count;
            return View(seznamTrid);
        }

        [HttpGet]
        public ActionResult Create()
        {
            TridaModel trida = new TridaModel
            {
                ZmenenoKdo = "( ͡° ͜ʖ ͡°)",
                Ulozeno = false
            };

            return View(trida);
        }

        [HttpPost]
        public ActionResult Create(TridaModel trida)
        {
            SkolaTridy skolaTridy = new SkolaTridy
            {
                Id          = Guid.NewGuid(),
                Nazev       = trida.Nazev,
                Rocnik      = trida.Rocnik,
                Tridni      = trida.Tridni,
                ZmenenoKdy  = DateTime.Now,
                ZmenenoKdo  = trida.ZmenenoKdo
            };

            new SkolaSoapClient().TridaCreate(skolaTridy);

            trida.Ulozeno = true;
            return View(trida);
        }

        [HttpGet]
        public ActionResult CreateForm()
        {
            TridaModel trida = new TridaModel
            {
                ZmenenoKdo = "( ͡° ͜ʖ ͡°)",
                Ulozeno = false
            };

            return View(trida);
        }

        [HttpPost]
        public ActionResult CreateForm(TridaModel trida)
        {
            SkolaTridy skolaTridy = new SkolaTridy
            {
                Id          = Guid.NewGuid(),
                Nazev       = trida.Nazev,
                Rocnik      = trida.Rocnik,
                Tridni      = trida.Tridni,
                ZmenenoKdy  = DateTime.Now,
                ZmenenoKdo  = trida.ZmenenoKdo
            };

            new SkolaSoapClient().TridaCreate(skolaTridy);

            string casNacteniUzivatele = Request["cas-nacteni"];

            trida.Ulozeno = true;
            return View(trida);
        }

        [HttpGet]
        public ActionResult CreateAjax()
        {
            TridaModel trida = new TridaModel
            {
                ZmenenoKdo = "( ͡° ͜ʖ ͡°)",
                Ulozeno = false
            };

            return View(trida);
        }

        [HttpPost]
        public ActionResult CreateAjax(TridaModel trida)
        {
            SkolaTridy skolaTridy = new SkolaTridy
            {
                Id          = Guid.NewGuid(),
                Nazev       = trida.Nazev,
                Rocnik      = trida.Rocnik,
                Tridni      = trida.Tridni,
                ZmenenoKdy  = DateTime.Now,
                ZmenenoKdo  = trida.ZmenenoKdo
            };

            new SkolaSoapClient().TridaCreate(skolaTridy);

            string casNacteniUzivatele = Request["cas-nacteni"];

            trida.Ulozeno = true;
            return Content("OK");
        }

        public ActionResult Delete(string id)
        {
            new SkolaSoapClient().TridaSmazat(id);
            return RedirectToAction("List");
        }

        [HttpGet]
        public ActionResult VratPocetTrid()
        {
            return Json(new Tuple<bool, int>(true, new SkolaSoapClient().TridaPocet()), JsonRequestBehavior.AllowGet);
        }
    }
}