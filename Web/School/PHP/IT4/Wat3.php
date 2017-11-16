<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat3</title>
  </head>
  <body>
    <form method="GET">
      <?php
        $x = 0;
        $y = 0;
        $areset = isset($_GET["x"]) && isset($_GET["y"]);
        
        if ($areset)
        {
          $x = $_GET["x"];
          $y = $_GET["y"];     
        }
      ?>
      
      <input type="number" name="x" value="<?php echo $x ?>">
      +
      <input type="number" name="y" value="<?php echo $y ?>">
      <input type="submit" value="=">
      
      <?php
        if ($areset)
        {
          echo $x + $y;
        }
      ?>
    </form>
  </body>
</html>
