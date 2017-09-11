using System;

[AttributeUsage(AttributeTargets.Method)]
public sealed class NavbarItemAttribute : Attribute
{
    private bool _hasDropdown;
    private bool _isInDropdown;

    public string DisplayName { get; }
    public int Order { get; }

    public bool HasDropdown
    {
        get { return _hasDropdown; }
        set
        {
            if (_hasDropdown != value)
            {
                ValidateDropdownProperties(value, IsInDropdown);
                _hasDropdown = value;
            }
        }
    }
    public bool IsHeaderLink { get; set; }
    public bool IsInDropdown
    {
        get { return _isInDropdown; }
        set
        {
            if (_isInDropdown != value)
            {
                ValidateDropdownProperties(HasDropdown, value);
                _isInDropdown = value;
            }
        }
    }
    public int DropdownId { get; set; }

    public NavbarItemAttribute(string displayName, int order)
    {
        if (string.IsNullOrWhiteSpace(displayName))
        {
            throw new ArgumentException("Value cannot be white space or null.", nameof(displayName));
        }

        DisplayName = displayName;
        Order = order;
    }

    private void ValidateDropdownProperties(bool hasDropdown, bool isInDropdown)
    {
        if (hasDropdown && isInDropdown)
        {
            throw new ArgumentException("NavbarItem cannot be in dropdown when it has a dropdown.");
        }
    }
}
