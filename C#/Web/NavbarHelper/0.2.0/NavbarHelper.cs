using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Web.Mvc;
using System.Web.Mvc.Html;

public static class NavbarHelper
{
    private const string NAVBAR_ITEM_FORMAT = "    <li class=\"{{0}}\">{0}</li>\n";
    private const string DROPDOWN_HEADER_FORMAT =
        "\n<li class=\"{{0}} dropdown\">\n" +
        "    {0}\n" +
        "    <ul class=\"dropdown-menu navgen-dropdown\">\n";
    private const string DROPDOWN_HEADER_ATTRIBUTES_START = " class=\"dropdown-toggle navgen-dropdown\" {0}role=\"button\" aria-haspopup=\"true\" aria-expanded=\"false\"";
    private const string DROPDOWN_HEADER_ATTRIBUTES_END = " <span class=\"caret\"></span>";
    private const string DROPDOWN_ITEM_FORMAT = "        <li>{0}</li>\n";
    private const string DROPDOWN_END_FORMAT =
        "    </ul>\n" +
        "</li>\n";

    private static IEnumerable<LinkInfo> sortedLinkInfo;
    
    public static string DropdownScript
    {
        get
        {
            return @"
$('.navgen-dropdown').mouseenter(function () {
$(this).prop('aria-expanded', true);
$(this).parent().addClass('open');
});
$('.navgen-dropdown').mouseleave(function () {
$(this).prop('aria-expanded', false);
$(this).parent().removeClass('open');
});";
        }
    }

    public static string GetNavbar(HtmlHelper html, ViewContext viewContext)
    {
        if (sortedLinkInfo == null)
        {
            Type[] types = Assembly.GetExecutingAssembly().GetTypes();
            IEnumerable<MethodInfo> methodsInfo = types.SelectMany(t => t.GetMethods()).Where(m => m.GetCustomAttributes(typeof(NavbarItemAttribute)).Any());

            var topLevelNavbarItems = methodsInfo.Select(m => new { MethodInfo = m, NIA = (NavbarItemAttribute)m.GetCustomAttribute(typeof(NavbarItemAttribute)) }).ToList();
            var dropdownLevelNavbarItems = topLevelNavbarItems.Where(a => a.NIA.IsInDropdown).ToList();

            foreach (var item in dropdownLevelNavbarItems)
            {
                topLevelNavbarItems.Remove(item);
            }

            Dictionary<int, LinkInfo> navbarItems = new Dictionary<int, LinkInfo>();

            foreach (var topLevelNavbarItem in topLevelNavbarItems)
            {
                string topLevelNavbarItemController = topLevelNavbarItem.MethodInfo.DeclaringType.Name.Replace("Controller", null);
                MvcHtmlString actionLink = html.ActionLink(topLevelNavbarItem.NIA.DisplayName, topLevelNavbarItem.MethodInfo.Name, topLevelNavbarItemController);

                StringBuilder htmlStringBuilder = new StringBuilder();

                if (topLevelNavbarItem.NIA.HasDropdown)
                {
                    // Could we replace this StringBuilder with Regex.Match(actionLink.ToHtmlString(), "\"(.*?)\"").Value?
                    // Who knows ¯\_(ツ)_/¯
                    StringBuilder actionLinkStringBuilder = new StringBuilder(actionLink.ToHtmlString());
                    actionLinkStringBuilder.Insert(2, string.Format(DROPDOWN_HEADER_ATTRIBUTES_START, topLevelNavbarItem.NIA.IsHeaderLink ? null : "data-toggle=\"dropdown\""));
                    actionLinkStringBuilder.Insert(actionLinkStringBuilder.Length - 4, DROPDOWN_HEADER_ATTRIBUTES_END);

                    htmlStringBuilder.AppendFormat(DROPDOWN_HEADER_FORMAT, actionLinkStringBuilder.ToString());
                    
                    foreach (var dropdownLevelNavbarItem in dropdownLevelNavbarItems.Where(i => i.NIA.DropdownId == topLevelNavbarItem.NIA.DropdownId).OrderBy(i => i.NIA.Order))
                    {
                        string dropdownLevelNavbarItemController = dropdownLevelNavbarItem.MethodInfo.DeclaringType.Name.Replace("Controller", null);
                        htmlStringBuilder.AppendFormat(DROPDOWN_ITEM_FORMAT, html.ActionLink(dropdownLevelNavbarItem.NIA.DisplayName, dropdownLevelNavbarItem.MethodInfo.Name, dropdownLevelNavbarItemController));
                    }

                    htmlStringBuilder.Append(DROPDOWN_END_FORMAT);
                }
                else
                {
                    htmlStringBuilder.Append(string.Format(NAVBAR_ITEM_FORMAT, actionLink));
                }

                navbarItems.Add(topLevelNavbarItem.NIA.Order, new LinkInfo(htmlStringBuilder.ToString(), topLevelNavbarItemController));
            }

            sortedLinkInfo = navbarItems.OrderBy(k => k.Key).Select(k => k.Value);
        }

        string controllerName = (string)viewContext.RouteData.Values["Controller"];
        StringBuilder navbarStringBuilder = new StringBuilder();

        foreach (LinkInfo info in sortedLinkInfo)
        {
            navbarStringBuilder.Append(string.Format(info.HtmlString, controllerName == info.ControllerName ? "active" : ""));
        }

        return navbarStringBuilder.ToString();
    }

    private sealed class LinkInfo
    {
        public string HtmlString { get; }
        public string ControllerName { get; }

        public LinkInfo(string htmlString, string controllerName)
        {
            if (string.IsNullOrWhiteSpace(htmlString))
            {
                throw new ArgumentException("Value cannot be white space or null.", nameof(htmlString));
            }

            if (string.IsNullOrWhiteSpace(controllerName))
            {
                throw new ArgumentException("Value cannot be white space or null.", nameof(controllerName));
            }

            HtmlString = htmlString;
            ControllerName = controllerName;
        }
    }
}
