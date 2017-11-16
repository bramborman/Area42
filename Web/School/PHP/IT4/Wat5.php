<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat5</title>
  </head>
  <body>
    <form method="GET">
      <input type="hidden" name="waat">
      <input type="submit">
      
      <?php
        if ($_GET)
        {
      ?>
        <table style="border: 1px solid black; border-collapse: collapse;">
          <tr style="border: 1px solid black;">
            <td style="border: 1px solid black;">1</td>
            <td style="border: 1px solid black;">2</td>
          </tr>
          <tr style="border: 1px solid black;">
            <td style="border: 1px solid black;">3</td>
            <td style="border: 1px solid black;">4</td>
          </tr>
        </table>
      <?php
        }
      ?>
    </form>
  </body>
</html>
