using MVC_WebService.App_Core;
using System.Web.Mvc;

namespace MVC_WebService.Controllers
{
    public class LogsController : Controller
    {
        public ActionResult Index()
        {
            ViewBag.NavigationLog   = Logger.GetNavigationLog().Replace("\n", "<br/>");
            ViewBag.CachedFileNames = GalleryCache.GetCachedFileNames();
            return View();
        }
    }
}