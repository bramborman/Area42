using MVC_Zaci.Models;
using System.Collections.Generic;
using System.Web.Mvc;

namespace MVC_Zaci.Controllers
{
    public sealed class ZakController : Controller
    {
        // GET: Zaci
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult VypisZaka()
        {
            return View(new ZakModel { Jmeno = "Jan", Prijmeni = "Gnymors", JeMuz = false, RokNarozeni = 1998 });
        }

        public ActionResult VypisZaka2()
        {
            return View(new ZakModel { Jmeno = "Jan", Prijmeni = "Gnymors", JeMuz = false, RokNarozeni = 1998 });
        }

        public ActionResult EditZaka()
        {
            return View(new ZakModel { Jmeno = "Jan", Prijmeni = "Gnymors", JeMuz = false, RokNarozeni = 1998 });
        }

        [HttpPost]
        public ActionResult EditZaka(ZakModel zakModel)
        {
            zakModel.JeMuz = Request.Form[nameof(zakModel.JeMuz)] == "on";
            return View(zakModel);
        }

        public ActionResult EditZaka2()
        {
            return View(new ZakModel { Jmeno = "Jan", Prijmeni = "Gnymors", JeMuz = false, RokNarozeni = 1998 });
        }
    }
}