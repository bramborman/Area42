<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat4</title>
  </head>
  <body>
    <form method="GET">
      <?php
        $age = 0;
        
        if ($_GET)
        {
          $age = $_GET["age"];   
        }
      ?>
      
      <input type="number" name="age" value="<?php echo $age ?>">
      <input type="submit">
      
      <?php
        if ($_GET)
        {
          echo "<br>";
          echo "Jsi ".($age >= 18 && $age < 120 ? "plnoletý" : ($age >= 120 ? "asi mrtvý" : ($age < 0 ? "nenarozen" : "")));
        }
      ?>
    </form>
  </body>
</html>
