using MVC_Database.AppCode.DB;
using MVC_Database.Models;
using System.Linq;
using System.Web.Mvc;

namespace MVC_Database.Controllers
{
    public class InfoOZapujceniController : Controller
    {
        public ActionResult Index()
        {
            return View(new InfoOZapujceniTableController().GetInfoOZapujceni().Select(i => (InfoOZapujceniModel)i));
        }
    }
}