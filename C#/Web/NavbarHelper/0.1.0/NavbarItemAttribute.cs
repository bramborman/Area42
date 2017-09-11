using System;

[AttributeUsage(AttributeTargets.Method)]
public sealed class NavbarItemAttribute : Attribute
{
    public string DisplayName { get; }
    public int Order { get; }

    public NavbarItemAttribute(string displayName, int order)
    {
        if (string.IsNullOrWhiteSpace(displayName))
        {
            throw new ArgumentException("Value cannot be white space or null.", nameof(displayName));
        }

        if (order < 0)
        {
            throw new ArgumentOutOfRangeException(nameof(order));
        }

        DisplayName = displayName;
        Order = order;
    }
}
