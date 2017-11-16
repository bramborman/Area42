<!DOCTYPE HTML>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">
    <meta name="generator" content="PSPad editor, www.pspad.com">
    <title>Wat1</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
  </head>
  <body class="container" style="margin-top: 1%;">
    <?php
      if (isset($_GET["waat"]))
      {
    ?>
        <div class="alert alert-info"><?php echo $_GET["waat"] ?></div>
    <?php
      }
    ?>
  
    <form action="Wat1.php" method="GET" class="form-group">     
      <label for="waat">Zadej text:</label>
      <input id="waat" name="waat" type="text" class="form-control">
      
      <br>
      <input type="submit" class="btn btn-primary">
    </form>
  </body>
</html>
