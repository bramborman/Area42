<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Test1</title>
  </head>
  <body>
    <form method="GET" style="background: purple;">
      <label for="dph">Zadej DPH:</label>
      <input type="number" id="dph" name="dph" />
      <br />
      <label for="dph">Cena s DPH:</label>
      <input type="number" id="celkem" name="celkem" />
      <br />
      <input type="submit" value="KLIK" />
    </form>
      
    <?php
      if (isset($_GET["dph"]) && isset($_GET["celkem"]))
      {
        $dph = $_GET["dph"];
        $celkem = $_GET["celkem"];
        
        if ($dph < 0 || $dph > 100)
        {
          echo "Špatné zadání";
        }
        else
        {
          $output = $celkem * ($dph / 100);
          echo "DPH za danou častku činí ".$output." Kč.";
        }
      }
    ?>
  </body>
</html>
