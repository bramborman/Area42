<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat10</title>
  </head>
  <body>
    <form method="GET">
      <input type="number" name="wat">
      <input type="submit" value="KLIK" />
    </form>
      
    <?php
      if (isset($_GET["wat"]))
      {
        $arr = range(1, $_GET["wat"]);
        
        for ($i = 0; $i < count($arr); $i++)
        {
            echo $arr[$i]." ";
        }
      }
    ?>
  </body>
</html>
