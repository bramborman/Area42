using MVC_Database.AppCode.DB;
using System.Collections.Generic;
using System.Web.Mvc;

namespace MVC_Database.Controllers
{
    public class ZaciController : Controller
    {
        public ActionResult Index()
        {
            DatabaseSchoolController controller = new DatabaseSchoolController();
            List<SkolaZaci> zaci = controller.GetAll();

            return View();
        }

        public ActionResult ZakPrijmeni()
        {
            return View(new DatabaseSchoolController().GetZaciByPrijmeni("Gnymors"));
        }
    }
}