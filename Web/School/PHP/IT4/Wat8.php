<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat8</title>
  </head>
  <body>
    <form method="GET">
      <input type="hidden" name="wat">
      <input type="submit" value="KLIK" />
    </form>
      
    <?php
      if (isset($_GET["wat"]))
      {
        $i = 150;
        
        while ($i > 100)
        {
          echo $i." ahoj <br />";
          $i -= 10;
        }
        
        do
        {
          echo $i." ahoj <br />";
        } while (($i -= 10) > 50);
        
        for (; $i > 0; $i -= 10)
        {
          echo $i." ahoj <br />";
        }
      }
    ?>
  </body>
</html>
