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
            return View(new KnihovnaTableController().GetAllOnZak(idZaka).Select(knihovna => (KnihovnaModel)knihovna));
        }
    }
}