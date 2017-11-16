<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat9</title>
  </head>
  <body>
    <form method="GET">
      <input type="hidden" name="wat">
      <input type="submit" value="KLIK" />
    </form>
      
    <?php
      if (isset($_GET["wat"]))
      {
        $weekDays = array("pondělí", "úterý", "středa", "čtvrtek", "pátek", "sobota", "neděle");
        
        for ($i = 0; $i < count($weekDays); $i++)
        {
          echo $weekDays[$i]."<br />";
        }
      }
    ?>
  </body>
</html>
