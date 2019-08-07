# # # # # # # # # # # # # # # # # # # #
# Project D          Since 29/01/2019 #
# # # # # # # # # # # # # # # # # # # #
#                                     #
#   >(' )    =(' )    -(' )           #
#    (  `` )_ (  `` )__ (  `` )__ _   #
# # # # # # # # # # # # # # # # # # # #

$DEBUG = $true

if ($DEBUG)
{
    function Debug-Variable($name, $value)
    {
        Write-Host "`$${name}: $value"
    }
}
else
{
    function Debug-Variable($name, $value)
    {
        # Should probably remain empty
    }
}

$bill = "=", ">", "=", "<"
$head = "(' )",       "( ')"
$body = "(  `` )", "( ´´  )"
$wave_char = '_'

$run = $true
# left: true/1, right: false/0
$orientation = $false
$orientation_int = $orientation / 1
$left

Debug-Variable "orientation" $orientation
Debug-Variable "orientation_int" $orientation_int

while ($run)
{
    
}
