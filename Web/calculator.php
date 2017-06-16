<!DOCTYPE HTML>
<html>
    <head>
        <title>Calculator</title>
    </head>
    <body>
        <style type="text/css">
            * {
                font-family: "Segoe UI";
            }

            input {
                width: 100%;
                height: 100%;
                background: lightgray;
                border-width: 10px;
                border-radius: 5px;
                outline: none;
                font-size: 50px; 
            }
      
            input:read-only {
                background: white;
                color: black;
            }
        </style>
    
        <?php
            # why php
            # js better
            $clearAll = isset($_GET['clearAll']) && $_GET['clearAll'] == 1;
            $state = !$clearAll && isset($_GET['state']) ? $_GET['state'] : 0;
            $originalState = $state;

            if ($state == 3)
            {
                $state = 2;
            }

            $operation = !$clearAll && isset($_GET['operation']) ? $_GET['operation'] : "";

            if (isset($_GET['input']) && !$clearAll)
            {
                if ($state == 1)
                {
                    $x = $_GET['input'];
                }
                else
                {
                    $x = $_GET['x'];
                    $y = $_GET['input'];
                    
                    switch ($operation)
                    {
                        case '+': $x += $y; break;
                        case '-': $x -= $y; break;
                        case '*': $x *= $y; break;
                        case '/':
                            if ($y !== "0")
                            {
                                $x /= $y;
                            }
                            else
                            {
                                $youKnow = array("(ง⸟ᨎ⸟)ง", "(ง⸟ ͟ʖ⸟)ง", "(⌐■ᨎ■)", "( ͡° ͜ʖ ͡°)", "(⌐■_■)", "¯\_(ツ)_/¯", "ಠ_ಠ", "ʢ◉ᴥ◉ʡ", "^‿^", "(づ◔ ͜ʖ◔)づ", "⤜(ʘ_ʘ)⤏", "ᗒ ͟ʖᗕ");
                                $x = $youKnow[rand(0, sizeof($youKnow) - 1)];
                            }

                            break;
                    }
                }
            }

            if (!$clearAll && isset($_GET['nextOperation']))
            {
                $nextOperation = $_GET['nextOperation'];

                if ($nextOperation != "")
                {
                    $operation = $nextOperation;
                }
            }
      
            $inputValue = $state == 2 ? $x : "0";
        ?>

        <form name="calc" method="get" style="width: 50%; height: 50%; position: absolute; top: 25%; left: 25%;">
            <input name="x" type="hidden" value="<?php echo isset($x) ? $x : "" ?>">
            <input name="operation" type="hidden" value="<?php echo $operation ?>">
            <input name="nextOperation" type="hidden">
            <input name="state" type="hidden" value="<?php echo $state ?>">
            <input name="clearAll" type="hidden" value="0">
    
            <table cellspacing="0" cellpadding="0" style="width: 100%; height: 100%;">
                <tr height="20%">
                    <td colspan="5">
                    <input name="input"
                           value="<?php echo $inputValue; ?>"
                           readonly
                           style="text-align: right; width: calc(100% - 20px)"
                           />
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="button" value="7" onclick="addNumber('7')">
                    </td>
                    <td>
                        <input type="button" value="8" onclick="addNumber('8')">
                    </td>
                    <td>
                        <input type="button" value="9" onclick="addNumber('9')">
                    </td>
                    <td>
                        <input id="clearButton" type="submit" value="<?php echo $inputValue === "0" ? "A" : "C"; ?>" onclick="return clearInput(false)">
                    </td>
                    <td>
                        <input type="button" value="←" onclick="clearInput(true)">
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="button" value="4" onclick="addNumber('4')">
                    </td>
                    <td>
                        <input type="button" value="5" onclick="addNumber('5')">
                    </td>
                    <td>
                        <input type="button" value="6" onclick="addNumber('6')">
                    </td>
                    <td>
                        <input type="submit" value="+" onclick="changeOperation('+')">
                    </td>
                    <td>
                        <input type="submit" value="×" onclick="changeOperation('*')">
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="button" value="1" onclick="addNumber('1')">
                    </td>
                    <td>
                        <input type="button" value="2" onclick="addNumber('2')">
                    </td>
                    <td>
                        <input type="button" value="3" onclick="addNumber('3')">
                    </td>
                    <td>
                        <input type="submit" value="-" onclick="changeOperation('-')">
                    </td>
                    <td>
                        <input type="submit" value="÷" onclick="changeOperation('/')">
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="button" value="0" onclick="addNumber('0')">
                    </td>
                    <td>
                        <input type="button" value="." onclick="comma()">
                    </td>
                    <td>
                        <input type="button" value="±" onclick="negate()">
                    </td>
                    <td colspan="2">
                        <input type="submit" value="=" onclick="return getResult()">
                    </td>
                </tr>
            </table>
        </form>
    
        <script type="text/javascript">
            var input = document.calc.input;
            var clearButton = document.getElementById("clearButton");

            function addNumber(number)
            {
                if (isNaN(input.value))
                {
                    return;
                }

                if (input.value == "0" || <?php echo $originalState ?> == 3)
                {
                    input.value = number;
                }
                else
                {
                    input.value += number;
                }

                clearButton.value = "C";
            }

            function clearInput(backSpace)
            {
                if (backSpace)
                {
                    if (input.value != "0")
                    {
                        input.value = input.value.slice(0, -1);
                    }

                    if (input.value == "")
                    {
                        input.value = "0";
                    }

                    return false;
                }
                else
                {
                    if (clearButton.value == "C")
                    {
                        clearButton.value = "A";
                        input.value = "0";

                        return false;
                    }
                    else
                    {
                        document.calc.clearAll.value = 1;
                        // document.calc.operation.value = null;
                        return true;
                    }
                }
            }
      
            function changeOperation(operation)
            {
                var state = document.calc.state.value == 1 || <?php echo $originalState ?> == 3 ? 3 : 1;

                if (state != 3)
                {
                    document.calc.operation.value = operation;
                }
                else
                {
                    document.calc.nextOperation.value = operation;
                }

                document.calc.state.value = state;
            }

            function comma()
            {
                if (input.value.indexOf('.') == -1)
                {
                    input.value += '.';
                }
            }

            function negate()
            {
                if (input.value[0] != '-')
                {
                    input.value = '-' + input.value;
                }
                else
                {
                    input.value = input.value.slice(1);
                }
            }

            function getResult()
            {
                if (document.calc.operation.value != "")
                {
                    document.calc.state.value = 2;
                    return true;
                }

                return false;
            }
        </script>
    </body>
</html>
