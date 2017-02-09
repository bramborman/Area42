using System.Web.Mvc;
using System.Web.Routing;

namespace MVC_WebService
{
    public class RouteConfig
    {
        public static void RegisterRoutes(RouteCollection routes)
        {
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{id}",
                defaults: new { controller = Constants.DEFAULT_CONTROLLER, action = Constants.DEFAULT_ACTION, id = UrlParameter.Optional }
            );
        }
    }
}
