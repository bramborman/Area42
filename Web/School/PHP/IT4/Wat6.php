<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <title>Wat6</title>
  </head>
  <body>
    <form method="GET">
      <input type="text" name="a">
      <input type="text" name="b">
      <input type="text" name="c">
      <input type="text" name="d">
      <input type="submit">
      
      <?php
        if ($_GET)
        {
      ?>
        <table style="border: 1px solid black; border-collapse: collapse;">
          <tr style="border: 1px solid black;">
            <td style="border: 1px solid black;"><?php echo $_GET["a"]; ?></td>
            <td style="border: 1px solid black;"><?php echo $_GET["b"]; ?></td>
          </tr>
          <tr style="border: 1px solid black;">
            <td style="border: 1px solid black;"><?php echo $_GET["c"]; ?></td>
            <td style="border: 1px solid black;"><?php echo $_GET["d"]; ?></td>
          </tr>
        </table>
      <?php
        }
      ?>
    </form>
  </body>
</html>
