using Sklad_lodi.Attributes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Web.Mvc;
using System.Web.Mvc.Html;

public static class NavbarHelper
{
    private static IEnumerable<LinkInfo> sortedLinkInfo;

    public static string GetNavbar(HtmlHelper html, ViewContext viewContext)
    {
        if (sortedLinkInfo == null)
        {
            Type[] types = Assembly.GetExecutingAssembly().GetTypes();
            IEnumerable<MethodInfo> methodsInfo = types.SelectMany(t => t.GetMethods()).Where(m => m.GetCustomAttributes(typeof(NavbarItemAttribute)).Any());
            UrlHelper urlHelper = new UrlHelper();
            Dictionary<int, LinkInfo> navbarItems = new Dictionary<int, LinkInfo>();

            foreach (MethodInfo methodInfo in methodsInfo)
            {
                string controller = methodInfo.DeclaringType.Name.Replace("Controller", "");
                string action = methodInfo.Name;
                NavbarItemAttribute nia = (NavbarItemAttribute)methodInfo.GetCustomAttribute(typeof(NavbarItemAttribute));

                navbarItems.Add(nia.Order, new LinkInfo($"<li class=\"{{0}}\">{html.ActionLink(nia.DisplayName, action, controller)}</li>", controller));
            }

            sortedLinkInfo = navbarItems.OrderBy(k => k.Key).Select(k => k.Value);
        }

        string controllerName = (string)viewContext.RouteData.Values["Controller"];
        StringBuilder stringBuilder = new StringBuilder();

        foreach (LinkInfo info in sortedLinkInfo)
        {
            stringBuilder.Append(string.Format(info.Link, controllerName == info.ControllerName ? "active" : ""));
        }

        return stringBuilder.ToString();
    }

    private sealed class LinkInfo
    {
        public string Link { get; }
        public string ControllerName { get; }

        public LinkInfo(string link, string controllerName)
        {
            if (string.IsNullOrWhiteSpace(link))
            {
                throw new ArgumentException("Value cannot be white space or null.", nameof(link));
            }

            if (string.IsNullOrWhiteSpace(controllerName))
            {
                throw new ArgumentException("Value cannot be white space or null.", nameof(controllerName));
            }

            Link = link;
            ControllerName = controllerName;
        }
    }
}
