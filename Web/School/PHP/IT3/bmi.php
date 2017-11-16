<!DOCTYPE HTML>
<html>
  <head>
    <title>BMI</title>
  </head>
  <body>
   <?php
    $weight = 58;
    $height = 1.8;
    $bmi    = round($weight / ($height * $height), 2);
    
    if ($bmi <= 16.5)
    {
      $message = "těžká podvýživa";
    }
    else if ($bmi <= 18.5)
    {
      $message = "podváha";
    }
    else if ($bmi <= 25)
    {
      $message = "ideální (zdravá) váha";
    }
    else if ($bmi <= 30)
    {
      $message = "nadváha";
    }
    else if ($bmi <= 35)
    {
      $message = "obezita prvního stupně";
    }
    else if ($bmi <= 40)
    {
      $message = "obezita druhého stupně";
    }
    else
    {
      $message = "obezita třetího stupně (též morbidní obezita)";
    }
    
    echo "BMI při výšce $height"."m a váze $weight"."kg je $bmi tzn. $message.";
   ?>
  </body>
</html>
