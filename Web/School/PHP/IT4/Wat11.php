<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat11</title>
  </head>
  <body>
    <form method="GET">
      Počet prvků: <input type="number" name="count">
      <br>
      Min: <input type="number" name="min">
      <br>
      Max: <input type="number" name="max">  
      <br>
      <input type="submit" value="KLIK" />
    </form>
      
    <?php
    
        if (isset($_GET["count"]) && isset($_GET["min"]) && isset($_GET["max"]))
        {
            $count = $_GET["count"];
            $min = $_GET["min"];
            $max = $_GET["max"];
            
            for ($i = 0; $i < $count; $i++)
            {
                $arr[$i] = rand($min, $max);
                echo $arr[$i]." ";
            }
            
            for ($i = 0; $i < $count - 1; $i++)
            {
                $sortMin = $i;
                
                for ($j = $i + 1; $j < $count; $j++)
                {
                    if ($arr[$j] < $arr[$sortMin])
                    {
                        $sortMin = $j;
                    }
                }
                
                if ($sortMin !== $i)
                {
                    $temp = $arr[$i];
                    $arr[$i] = $arr[$sortMin];
                    $arr[$sortMin] = $temp;
                }
            }
            
            echo "<br>";
            
            for ($i = 0; $i < $count; $i++)
            {
                echo $arr[$i]." ";
            }
        }
    ?>
  </body>
</html>
