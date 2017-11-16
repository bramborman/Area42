<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat13</title>
  </head>
  <body>
    <form method="GET">
      <input type="text" name="wat" value="<?php echo isset($_GET["wat"]) ? $_GET["wat"] : ""; ?>" >
      <input type="submit" value="KLIK" />
    </form>
      
    <?php
    
        if (isset($_GET["wat"]))
        {
            function waaat($value)
            {
                $value = strtolower($value);
                
                $a = 0;
                $e = 0;
                $i = 0;
                $o = 0;
                $u = 0;
                $y = 0;
                
                for ($j = 0; $j < strlen($value); $j++)
                {
                    switch ($value[$j])
                    {
                        case "a":
                            $a++;
                            break;
                        
                        case "e":
                            $e++;
                            break;
                        
                        case "i":
                            $i++;
                            break;
                        
                        case "o":
                            $o++;
                            break;
                        
                        case "u":
                            $u++;
                            break;
                        
                        case "y":
                            $y++;
                            break;
                    }
                }
                
                printf("A: %d E: %d I: %d O: %d U: %d Y: %d", $a, $e, $i, $o, $u, $y);
            }
            
            waaat($_GET["wat"]);
        }
    ?>
  </body>
</html>
