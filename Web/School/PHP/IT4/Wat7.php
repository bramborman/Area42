<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat7</title>
    <style>
      body {
        font-size: 10px;
      }
      
      table, tr, td {
        border: 1px solid black;
        border-collapse: collapse;
        font-size: 1.5em;
        text-align: center;
      }
      
      td {
        width: 2.5em;
        height: 2.5em;
      } 
    </style>
  </head>
  <body>
    <form method="GET">
      <input type="number" name="rows">
      <input type="number" name="columns">
      <input type="submit">
      
      <?php
        if (isset($_GET["rows"]) && isset($_GET["columns"]))
        {
          $rows = is_numeric($_GET["rows"]) ? $_GET["rows"] : 2;
          $columns = is_numeric($_GET["columns"]) ? $_GET["columns"] : 2;
      ?>
          <table>
          
          <?php
            for ($r = 0; $r < $rows; $r++)
            {
          ?>
            <tr>
            
            <?php
              for ($c = 0; $c < $columns; $c++)
              {
                $n = (($r * $columns) + $c + 1);
            ?>
                <td><?php echo $n.".".strrev($n); ?></td>
            <?php
              }
            ?>
            
            </tr>
          <?php
            }
          ?>
          </table>
      <?php
        }
      ?>
    </form>
  </body>
</html>
