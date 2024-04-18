Imports System.IO.Ports
Imports System.Management

Public Class Form1
    Dim comPORT As String
    Dim boArduinoDeviceInfo As Boolean
    Dim DaysOfTheMonth As Short
    Dim MoreEventsCounter As Short
    Dim Aux_Day As Short
    Dim Aux_Month As Short
    Dim Aux_Year As String
    Dim boMoreEvents As Boolean
    Dim RSComandAttempts As Short
    Dim SNComandAttempts As Short
    Dim RSComandAttempt As Boolean


    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        comPORT = ""
        RSComandAttempts = 1
        SNComandAttempts = 1
        RSComandAttempt = False
        DateTimePicker1.Value = DateTime.Now
        Button1.Enabled = False
        Button2.Enabled = False
        Button3.Enabled = False
        Button5.Enabled = False
        DateTimePicker1.Enabled = False
        boMoreEvents = False
        boArduinoDeviceInfo = False
        NumericUpDown1.Enabled = False
        Label4.Visible = False
        CheckBox1.Enabled = False
        MoreEventsCounter = 1
        TextBox1.BackColor = Color.LightGray
        TextBox2.BackColor = Color.LightGray
        Button1.BackColor = Color.LightGray
        Button2.BackColor = Color.LightGray
        Button3.BackColor = Color.LightGray
        Button5.BackColor = Color.LightGray

        Try
            ' Show all available COM ports.
            For Each sp As String In My.Computer.Ports.SerialPortNames
                ComboBox1.Items.Add(sp)
            Next

            ' Dim searcher As New ManagementObjectSearcher(
            '"root\cimv2",
            '"SELECT * FROM Win32_SerialPort")

            ' For Each queryObj As ManagementObject In searcher.Get()

            'ComboBox1.Items.Add(queryObj("Name"))
            'Next
        Catch err As ManagementException
            MsgBox("Ocorreu um erro durante a pesquisa da Porta Série: ", MsgBoxStyle.Critical)
        End Try

    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged
        If (ComboBox1.SelectedItem <> "") Then
            comPORT = ComboBox1.SelectedItem
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click

        Try
            If (Button4.Text = "Conectar") Then
                If (comPORT.StartsWith("COM")) Then
                    SerialPort1.Close()
                    SerialPort1.PortName = comPORT
                    SerialPort1.BaudRate = 115200
                    SerialPort1.DataBits = 8
                    SerialPort1.Parity = Parity.None
                    SerialPort1.StopBits = StopBits.One
                    SerialPort1.Handshake = Handshake.None
                    SerialPort1.Encoding = System.Text.Encoding.Default
                    SerialPort1.ReadTimeout = 5000

                    SerialPort1.Open()

                    GetArduinoDeviceInfo()

                    If boArduinoDeviceInfo = True Then
                        COMport_LBL.Text = "Conectado"
                        COMport_LBL.ForeColor = Color.Green
                        Button1.Enabled = True
                        Button5.Enabled = True
                        Button4.ForeColor = Color.Red
                        Button4.Text = "Disconectar"
                        boArduinoDeviceInfo = False
                        CheckBox1.Enabled = True
                        DateTimePicker1.Enabled = True
                        TextBox1.BackColor = Color.WhiteSmoke
                        TextBox2.BackColor = Color.WhiteSmoke
                        Button1.BackColor = Color.LightGreen
                        Button5.BackColor = Color.IndianRed
                    End If

                Else
                    MsgBox("Selecionar Porta de Comunicação", MsgBoxStyle.Information)
                End If

            Else
                SerialPort1.Close()
                ProgressBar1.Value = 0
                COMport_LBL.Text = "Disconectado"
                COMport_LBL.ForeColor = Color.Red
                Button1.Enabled = False
                Button2.Enabled = False
                Button3.Enabled = False
                Button5.Enabled = False
                DateTimePicker1.Enabled = False
                CheckBox1.CheckState = False
                CheckBox1.Enabled = False
                Button4.ForeColor = Color.Green
                Button4.Text = "Conectar"
                TextBox1.Text = ""
                TextBox2.Text = ""
                TextBox3.Text = ""
                TextBox1.BackColor = Color.LightGray
                TextBox2.BackColor = Color.LightGray
                Button1.BackColor = Color.LightGray
                Button2.BackColor = Color.LightGray
                Button3.BackColor = Color.LightGray
                Button5.BackColor = Color.LightGray
            End If

        Catch err As ManagementException
            MsgBox("Erro ao conectar com " & comPORT, MsgBoxStyle.Critical)
        End Try

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Button2.BackColor = Color.LightGray
        Button3.BackColor = Color.LightGray
        Dim AuxChar As Char
        Dim AuxStr As String
        Dim Day As String
        Dim Month As String
        Dim Year As String
        Dim NrOfAttempts As Short

        Try
            TextBox3.Text = ""
            AuxStr = ""
            AuxChar = ""
            Day = ""
            Month = ""
            Year = ""
            NrOfAttempts = 4
            Button2.Enabled = False
            Button3.Enabled = False
            Button5.Enabled = False

            If SerialPort1.IsOpen = True Then

                If boMoreEvents = False Then
                    If CheckBox1.Checked = False Then ProgressBar1.Maximum = 100 Else ProgressBar1.Maximum = NumericUpDown1.Value * 100
                    StrArduinoList = ""
                    TotalArduinoLoaded = 0
                    ProgressBar1.Value = 0
                    RSComandAttempt = False
                    Day = Mid(DateTimePicker1.Value, 1, 2)
                    Month = Mid(DateTimePicker1.Value, 4, 2)
                    Year = Mid(DateTimePicker1.Value, 7, 4)
                    Aux_Day = Day
                    Aux_Month = Month
                    Aux_Year = Year
                    SerialPort1.Write("@RSED" & Day & Month & Year & "@")
                ElseIf boMoreEvents = True Then
                    If RSComandAttempt = False Then
                        MoreEventsCounter = MoreEventsCounter + 1
                        Aux_Day = Aux_Day + 1
                        If Aux_Day > DaysOfTheMonth Then
                            Aux_Day = 1
                            Aux_Month = Aux_Month + 1
                            If Aux_Month > 12 Then
                                Aux_Month = 1
                                Aux_Year = Aux_Year + 1
                            End If
                        End If
                    Else
                        ProgressBar1.Maximum = ProgressBar1.Maximum + 100
                        RSComandAttempt = False
                    End If

                    If Aux_Day <= 9 And Aux_Month >= 10 Then
                            SerialPort1.Write("@RSED" & "0" & Aux_Day & Aux_Month & Aux_Year & "@")
                        ElseIf Aux_Month <= 9 And Aux_Day >= 10 Then
                            SerialPort1.Write("@RSED" & Aux_Day & "0" & Aux_Month & Aux_Year & "@")
                        ElseIf Aux_Day <= 9 And Aux_Month <= 9 Then
                            SerialPort1.Write("@RSED" & "0" & Aux_Day & "0" & Aux_Month & Aux_Year & "@")
                        Else
                            SerialPort1.Write("@RSED" & Aux_Day & Aux_Month & Aux_Year & "@")
                        End If
                    End If

                If CheckBox1.Checked = False Then ProgressBar1.Value = 100 Else ProgressBar1.Value = ProgressBar1.Value + 100

                Threading.Thread.Sleep(1000)

                Do Until SerialPort1.BytesToRead = 0
                    AuxChar = Chr(SerialPort1.ReadChar)
                    AuxStr &= AuxChar
                Loop

                If AuxStr = "" Then
                    MsgBox("Não foram recebidos nenhuns resultados - Tente novamente.", MsgBoxStyle.Critical, "Download Registos")
                    RSComandAttempts = 1
                    Button5.Enabled = True
                    Exit Sub

                ElseIf AuxStr.StartsWith("@WSCNR@") Then
                    If RSComandAttempts <= NrOfAttempts Then
                        RSComandAttempt = True
                        RSComandAttempts += 1
                        Button1.PerformClick()
                    Else
                        MsgBox("O pedido não foi recebido com sucesso pelo ATmega - Tente novamente.", MsgBoxStyle.Critical, "Download Registos")
                        RSComandAttempts = 1
                        Button5.Enabled = True
                        Exit Sub
                    End If

                ElseIf AuxStr.StartsWith("@WSOFE@") Then
                    If CheckBox1.Checked = True Then
                        If boMoreEvents = False Then
                            boMoreEvents = True
                            Button1.PerformClick()
                        ElseIf boMoreEvents = True Then
                            If MoreEventsCounter >= NumericUpDown1.Value Then
                                MsgBox("Dados Recebidos com sucesso!" & vbNewLine & TotalArduinoLoaded & " Registos Foram Recebidos.", MsgBoxStyle.Information, "Download Registos")
                                DisplayArduinoEvents()
                                TextBox3.Text &= StrArduinoList
                                MoreEventsCounter = 1
                                boMoreEvents = False
                                Button2.Enabled = True
                                Button3.Enabled = True
                                Button5.Enabled = True
                                Button2.BackColor = Color.LightGreen
                                Button3.BackColor = Color.LightGreen
                            Else
                                Button1.PerformClick()
                            End If
                        End If
                    Else
                        MsgBox("Erro ao abrir o ficheiro " & Day & "/" & Month & "/" & Year & " - O ficheiro poderá não existir ou estar danificado.", MsgBoxStyle.Critical, "Download Registos")
                        RSComandAttempts = 1
                        Button5.Enabled = True
                        Exit Sub
                    End If
                ElseIf AuxStr.StartsWith("@WSNFF@") Then
                    If CheckBox1.Checked = True Then
                        If boMoreEvents = False Then
                            boMoreEvents = True
                            Button1.PerformClick()
                        ElseIf boMoreEvents = True Then
                            If MoreEventsCounter >= NumericUpDown1.Value Then
                                If TotalArduinoLoaded = 0 Then
                                    MsgBox("Nao foram encontrados nenhuns ficheiros no cartão SD para as datas: " & Label4.Text, MsgBoxStyle.Information, "Download Registos")
                                Else
                                    MsgBox("Dados Recebidos com sucesso!" & vbNewLine & TotalArduinoLoaded & " Registos Foram Recebidos.", MsgBoxStyle.Information, "Download Registos")
                                    DisplayArduinoEvents()
                                    TextBox3.Text &= StrArduinoList
                                    MoreEventsCounter = 1
                                    boMoreEvents = False
                                    Button2.Enabled = True
                                    Button3.Enabled = True
                                    Button5.Enabled = True
                                    Button2.BackColor = Color.LightGreen
                                    Button3.BackColor = Color.LightGreen
                                End If

                            Else
                                Button1.PerformClick()
                            End If
                        End If
                    Else
                        MsgBox("O ficheiro com a data " & Day & "/" & Month & "/" & Year & " não foi encontrado no cartão SD.", MsgBoxStyle.Information, "Download Registos")
                        RSComandAttempts = 1
                        Button5.Enabled = True
                        Exit Sub
                    End If
                ElseIf AuxStr.StartsWith("@WSNCF@") Then
                    MsgBox("O Cartão SD não foi encontrado - Verifique se o cartão está inserido corretamente.", MsgBoxStyle.Critical, "Download Registos")
                    RSComandAttempts = 1
                    Button5.Enabled = True
                    Exit Sub
                ElseIf AuxStr.StartsWith("@WSED|") And AuxStr.EndsWith("|@") Then
                    StrEventsReceived = AuxStr
                        LoadArduinoEvents()
                        If Flg_LoadArduinoList = True Then
                            If CheckBox1.Checked = True Then
                                If boMoreEvents = False Then
                                    boMoreEvents = True
                                    Button1.PerformClick()
                                ElseIf boMoreEvents = True Then
                                    If MoreEventsCounter >= NumericUpDown1.Value Then
                                    MsgBox("Dados Recebidos com sucesso!" & vbNewLine & TotalArduinoLoaded & " Registos Foram Recebidos.", MsgBoxStyle.Information, "Download Registos")
                                    DisplayArduinoEvents()
                                        TextBox3.Text &= StrArduinoList
                                        MoreEventsCounter = 1
                                        boMoreEvents = False
                                        Button2.Enabled = True
                                    Button3.Enabled = True
                                    Button5.Enabled = True
                                    Button2.BackColor = Color.LightGreen
                                        Button3.BackColor = Color.LightGreen
                                    Else
                                        Button1.PerformClick()
                                    End If
                                End If
                            Else
                            MsgBox("Dados Recebidos com sucesso!" & vbNewLine & TotalArduinoLoaded & " Registos Foram Recebidos.", MsgBoxStyle.Information, "Download Registos")
                            DisplayArduinoEvents()
                                TextBox3.Text = StrArduinoList
                                Button2.Enabled = True
                            Button3.Enabled = True
                            Button5.Enabled = True
                            Button2.BackColor = Color.LightGreen
                                Button3.BackColor = Color.LightGreen
                                StrEventsReceived = ""
                            End If
                        ElseIf Flg_LoadArduinoList = False Then
                            RSComandAttempts = 1
                            Button2.Enabled = False
                        Button3.Enabled = False
                        Button2.BackColor = Color.LightGray
                        Button3.BackColor = Color.LightGray
                        Button5.Enabled = True
                        Exit Sub
                        End If
                    Else
                        If CheckBox1.Checked = True Then
                        If boMoreEvents = False Then
                            boMoreEvents = True
                            StrEventsReceived = ""
                            Button1.PerformClick()
                        ElseIf boMoreEvents = True Then
                            If MoreEventsCounter >= NumericUpDown1.Value Then
                                MsgBox("Dados Recebidos com sucesso!" & vbNewLine & TotalArduinoLoaded & " Registos Foram Recebidos.", MsgBoxStyle.Information, "Download Registos")
                                DisplayArduinoEvents()
                                TextBox3.Text &= StrArduinoList
                                MoreEventsCounter = 1
                                boMoreEvents = False
                                Button2.Enabled = True
                                Button3.Enabled = True
                                Button5.Enabled = True
                                Button2.BackColor = Color.LightGreen
                                Button3.BackColor = Color.LightGreen
                            Else
                                Button1.PerformClick()
                            End If
                        End If
                    Else
                        MsgBox("Erro ao abrir o ficheiro " & Day & "/" & Month & "/" & Year & " - O ficheiro poderá não existir ou estar danificado.", MsgBoxStyle.Critical, "Download Registos")
                        RSComandAttempts = 1
                        Button5.Enabled = True
                        Exit Sub
                    End If
                End If
            Else
                MsgBox(" O Sistema não está conectado ao Atmega.", MsgBoxStyle.Critical, "Download Registos")
            End If
        Catch ex As Exception
            MsgBox("Erro ao Executar o Download de Registos - Tente Novamente.", MsgBoxStyle.Critical, "Download Registos")
            RSComandAttempts = 1
        End Try

        RSComandAttempts = 1

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click

        Dim Aux1 As String

        SaveFileDialog1.Filter = "(*.txt)|*.txt|All files (*.*)|*.*"
        DialogResult = SaveFileDialog1.ShowDialog()

        Aux1 = SaveFileDialog1.FileName

        If Aux1 <> Nothing And DialogResult <> Windows.Forms.DialogResult.Cancel Then
            SaveDataIntoTextFile(Aux1)
            Aux1 = MsgBox("Ficheiro Guardado com Sucesso!", MsgBoxStyle.Information, "Guardar Ficheiro Texto")

        End If

    End Sub

    Private Sub Form1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.FormClosing
        SerialPort1.Close()
    End Sub

    Private Sub GetArduinoDeviceInfo()

        Dim AuxChar As Char
        Dim AuxStr As String
        Dim A_AuxStr() As String
        Dim NrOfAttempts As Short

        AuxStr = ""
        DeviceSN = ""
        DeviceMonth = ""
        DeviceYear = ""
        NrOfAttempts = 5

        If SerialPort1.IsOpen = True Then
            SerialPort1.Write("@RSSN@")
        End If

        Threading.Thread.Sleep(400)

        Do Until SerialPort1.BytesToRead = 0
            AuxChar = Chr(SerialPort1.ReadChar)
            AuxStr &= AuxChar
        Loop

        If AuxStr = "" Then
            MsgBox("Falha ao Receber Informação do Controlador Remoto. Tente Novamente", MsgBoxStyle.Critical, "GetArduinoDeviceInfo()")
            RSComandAttempts = 1
            Exit Sub

        ElseIf AuxStr.StartsWith("@WSCNR@") Then
            If RSComandAttempts <= NrOfAttempts Then
                RSComandAttempts += 1
                GetArduinoDeviceInfo()

            Else
                MsgBox("@WSCNR@: O Comando nao foi recebido pelo controlador remoto para obter ligação. Tente Novamente", MsgBoxStyle.Critical, "GetArduinoDeviceInfo()")
                RSComandAttempts = 1
                Exit Sub
            End If

        ElseIf AuxStr.StartsWith("@WSSN|") And AuxStr.EndsWith("|@") Then
            A_AuxStr = AuxStr.Split("|")
            DeviceSN = A_AuxStr(1)
            DeviceYear = A_AuxStr(3)

            Select Case A_AuxStr(2)
                Case "1"
                    DeviceMonth = "Janeiro"
                Case "2"
                    DeviceMonth = "Fevereiro"
                Case "3"
                    DeviceMonth = "Março"
                Case "4"
                    DeviceMonth = "Abril"
                Case "5"
                    DeviceMonth = "Maio"
                Case "6"
                    DeviceMonth = "Junho"
                Case "7"
                    DeviceMonth = "Julho"
                Case "8"
                    DeviceMonth = "Agosto"
                Case "9"
                    DeviceMonth = "Setembro"
                Case "10"
                    DeviceMonth = "Outubro"
                Case "11"
                    DeviceMonth = "Novembro"
                Case "12"
                    DeviceMonth = "Dezembro"
            End Select

            TextBox2.Text = DeviceSN
            TextBox1.Text = DeviceMonth & " de " & DeviceYear

            boArduinoDeviceInfo = True
            RSComandAttempts = 1

        End If

    End Sub

    Private Sub DateTimePicker1_ValueChanged(sender As Object, e As EventArgs) Handles DateTimePicker1.ValueChanged
        Dim Day As String
        Dim Month As String
        Dim Year As String

        Day = Mid(DateTimePicker1.Value, 1, 2)
        Month = Mid(DateTimePicker1.Value, 4, 2)
        Year = Mid(DateTimePicker1.Value, 7, 4)

        MoreEventsDateUpdate()

        If CheckBox1.Checked = True Then

            Button1.Text = "Download Registos: " & Label4.Text
            EventsDate = Label4.Text

        Else

            Button1.Text = "Download de Registos: " & Day & "/" & Month & "/" & Year
            EventsDate = Day & "/" & Month & "/" & Year
        End If


    End Sub

    Private Sub NumericUpDown1_ValueChanged(sender As Object, e As EventArgs) Handles NumericUpDown1.ValueChanged

        MoreEventsDateUpdate()

        Button1.Text = "Download Registos: " & Label4.Text
        EventsDate = Label4.Text


    End Sub

    Private Sub MoreEventsDateUpdate()
        Dim Day As String
        Dim Month As String
        Dim Year As String
        Dim AuxDay As Short
        Dim AuxMonth As Short
        Dim AuxYear As Short

        Day = Mid(DateTimePicker1.Value, 1, 2)
        Month = Mid(DateTimePicker1.Value, 4, 2)
        Year = Mid(DateTimePicker1.Value, 7, 4)

        Select Case Month
            Case "01"
                DaysOfTheMonth = 31
            Case "02"
                DaysOfTheMonth = 28
            Case "03"
                DaysOfTheMonth = 31
            Case "04"
                DaysOfTheMonth = 30
            Case "05"
                DaysOfTheMonth = 31
            Case "06"
                DaysOfTheMonth = 30
            Case "07"
                DaysOfTheMonth = 31
            Case "08"
                DaysOfTheMonth = 31
            Case "09"
                DaysOfTheMonth = 30
            Case "10"
                DaysOfTheMonth = 31
            Case "11"
                DaysOfTheMonth = 30
            Case "12"
                DaysOfTheMonth = 31

        End Select

        AuxDay = Day + NumericUpDown1.Value - 1
        AuxYear = Year
        If AuxDay > DaysOfTheMonth Then
            AuxDay = AuxDay - DaysOfTheMonth
            AuxMonth = Month + 1
            If AuxMonth > 12 Then
                AuxMonth = 1
                AuxYear = Year + 1
            End If
        Else
            AuxDay = Day + NumericUpDown1.Value - 1
            AuxMonth = Month
            Button1.Text = "Download de Registos: " & Day & "/" & Month & "/" & Year
            EventsDate = Day & "/" & Month & "/" & Year
        End If

        If AuxDay <= 9 And AuxMonth >= 10 Then
            Label4.Text = Day & "/" & Month & "/" & Year & " - " & "0" & AuxDay & "/" & AuxMonth & "/" & AuxYear
            EventsDate = Label4.Text
        ElseIf AuxMonth <= 9 And AuxDay >= 10 Then
            Label4.Text = Day & "/" & Month & "/" & Year & " - " & AuxDay & "/" & "0" & AuxMonth & "/" & AuxYear
            EventsDate = Label4.Text
        ElseIf AuxDay <= 9 And AuxMonth <= 9 Then
            Label4.Text = Day & "/" & Month & "/" & Year & " - " & "0" & AuxDay & "/" & "0" & AuxMonth & "/" & AuxYear
            EventsDate = Label4.Text
        Else
            Label4.Text = Day & "/" & Month & "/" & Year & " - " & AuxDay & "/" & AuxMonth & "/" & AuxYear
            EventsDate = Label4.Text
        End If

    End Sub

    Private Sub CheckBox1_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox1.CheckedChanged

        Dim Day As String
        Dim Month As String
        Dim Year As String

        Day = Mid(DateTimePicker1.Value, 1, 2)
        Month = Mid(DateTimePicker1.Value, 4, 2)
        Year = Mid(DateTimePicker1.Value, 7, 4)

        If CheckBox1.Checked = True Then
            CheckBox1.ForeColor = Color.Green
            NumericUpDown1.Enabled = True
            Label4.Visible = True
            Button1.Text = "Download Registos: " & Label4.Text
            EventsDate = Label4.Text
        Else
            CheckBox1.ForeColor = Color.Black
            NumericUpDown1.Enabled = False
            Label4.Visible = False
            Button1.Text = "Download de Registos: " & Day & "/" & Month & "/" & Year
            EventsDate = Day & "/" & Month & "/" & Year

        End If

    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click

        Dim Aux1 As String

        SaveFileDialog1.Filter = "Excel files (*.xlsx)|*.xlsx|All files (*.*)|*.*"

        DialogResult = SaveFileDialog1.ShowDialog()

        Aux1 = SaveFileDialog1.FileName

        If Aux1 <> Nothing And DialogResult <> Windows.Forms.DialogResult.Cancel Then
            If SaveDataIntoExcelSheet(Aux1) Then
                Aux1 = MsgBox("Ficheiro Guardado com Sucesso!", MsgBoxStyle.Information, "Guardar Ficheiro Excel")
            Else
                Aux1 = MsgBox("Erro: O ficheiro não foi guardado.", MsgBoxStyle.Information, "Guardar Ficheiro Excel")
            End If
        End If

    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click

        Button2.BackColor = Color.LightGray
        Button3.BackColor = Color.LightGray
        Dim AuxChar As Char
        Dim AuxStr As String
        Dim Day As String
        Dim Month As String
        Dim Year As String
        Dim NrOfAttempts As Short
        Dim MsgResult As String

        Try
            If boMoreEvents = False Then
                Day = Mid(DateTimePicker1.Value, 1, 2)
                Month = Mid(DateTimePicker1.Value, 4, 2)
                Year = Mid(DateTimePicker1.Value, 7, 4)
                If CheckBox1.Checked = False Then MsgResult = MsgBox("Apagar todos os registos para a data selecionada:" & " " & Day & "/" & Month & "/" & Year, MsgBoxStyle.YesNo, "Apagar Registos?")
                If CheckBox1.Checked = True Then MsgResult = MsgBox("Apagar todos os registos para as datas:" & " " & Label4.Text, MsgBoxStyle.YesNo, "Apagar Registos?")
                If MsgResult = vbNo Then
                    Exit Sub
                End If
            End If


            TextBox3.Text = ""
            AuxStr = ""
            AuxChar = ""
            Day = ""
            Month = ""
            Year = ""
            NrOfAttempts = 4
            Button2.Enabled = False
            Button3.Enabled = False
            Button1.Enabled = False

            If SerialPort1.IsOpen = True Then

                If boMoreEvents = False Then
                    If CheckBox1.Checked = False Then ProgressBar1.Maximum = 100 Else ProgressBar1.Maximum = NumericUpDown1.Value * 100
                    ProgressBar1.Value = 0
                    TotalFilesDeleted = 0
                    RSComandAttempt = False
                    Day = Mid(DateTimePicker1.Value, 1, 2)
                    Month = Mid(DateTimePicker1.Value, 4, 2)
                    Year = Mid(DateTimePicker1.Value, 7, 4)
                    Aux_Day = Day
                    Aux_Month = Month
                    Aux_Year = Year
                    SerialPort1.Write("@RSFD" & Day & Month & Year & "@")
                ElseIf boMoreEvents = True Then
                    If RSComandAttempt = False Then
                        MoreEventsCounter = MoreEventsCounter + 1
                        Aux_Day = Aux_Day + 1
                        If Aux_Day > DaysOfTheMonth Then
                            Aux_Day = 1
                            Aux_Month = Aux_Month + 1
                            If Aux_Month > 12 Then
                                Aux_Month = 1
                                Aux_Year = Aux_Year + 1
                            End If
                        End If
                    Else
                        ProgressBar1.Maximum = ProgressBar1.Maximum + 100
                        RSComandAttempt = False
                    End If

                    If Aux_Day <= 9 And Aux_Month >= 10 Then
                        SerialPort1.Write("@RSFD" & "0" & Aux_Day & Aux_Month & Aux_Year & "@")
                    ElseIf Aux_Month <= 9 And Aux_Day >= 10 Then
                        SerialPort1.Write("@RSFD" & Aux_Day & "0" & Aux_Month & Aux_Year & "@")
                    ElseIf Aux_Day <= 9 And Aux_Month <= 9 Then
                        SerialPort1.Write("@RSFD" & "0" & Aux_Day & "0" & Aux_Month & Aux_Year & "@")
                    Else
                        SerialPort1.Write("@RSFD" & Aux_Day & Aux_Month & Aux_Year & "@")
                    End If
                End If

                If CheckBox1.Checked = False Then ProgressBar1.Value = 100 Else ProgressBar1.Value = ProgressBar1.Value + 100

                Threading.Thread.Sleep(750)

                Do Until SerialPort1.BytesToRead = 0
                    AuxChar = Chr(SerialPort1.ReadChar)
                    AuxStr &= AuxChar
                Loop

                If AuxStr = "" Then
                    MsgBox("Não foi possivel executar o comando - Tente novamente.", MsgBoxStyle.Critical, "Apagar Registos")
                    RSComandAttempts = 1
                    Exit Sub

                ElseIf AuxStr.StartsWith("@WSCNR@") Then
                    If RSComandAttempts <= NrOfAttempts Then
                        RSComandAttempt = True
                        RSComandAttempts += 1
                        Button5.PerformClick()
                    Else
                        MsgBox("O pedido não foi recebido com sucesso pelo ATmega - Tente novamente.", MsgBoxStyle.Critical, "Apagar Registos")
                        RSComandAttempts = 1
                        Exit Sub
                    End If
                ElseIf AuxStr.StartsWith("@WSNFF@") Then
                    If CheckBox1.Checked = True Then
                        If boMoreEvents = False Then
                            boMoreEvents = True
                            Button5.PerformClick()
                        ElseIf boMoreEvents = True Then
                            If MoreEventsCounter >= NumericUpDown1.Value Then
                                MoreEventsCounter = 1
                                boMoreEvents = False
                                Button2.Enabled = True
                                Button3.Enabled = True
                                Button1.Enabled = True
                                Button2.BackColor = Color.LightGreen
                                Button3.BackColor = Color.LightGreen
                                If TotalFilesDeleted = 0 Then
                                    MsgBox("Nao foram encontrados nenhuns ficheiros no cartão SD para as datas: " & Label4.Text, MsgBoxStyle.Information, "Apagar Registos")
                                Else
                                    MsgBox("Dados Apagados com sucesso!" & vbNewLine & TotalFilesDeleted & " Ficheiros Foram Apagados.", MsgBoxStyle.Information, "Apagar Registos")
                                    MoreEventsCounter = 1
                                    boMoreEvents = False
                                    Button2.Enabled = True
                                    Button3.Enabled = True
                                    Button1.Enabled = True
                                    Button2.BackColor = Color.LightGreen
                                    Button3.BackColor = Color.LightGreen
                                End If
                            Else
                                Button5.PerformClick()
                            End If
                        End If
                    Else
                        MsgBox("O ficheiro com a data " & Day & "/" & Month & "/" & Year & " não foi encontrado no cartão SD.", MsgBoxStyle.Information, "Apagar Registos")
                        RSComandAttempts = 1
                        Exit Sub
                    End If
                ElseIf AuxStr.StartsWith("@WSNCF@") Then
                    MsgBox("O Cartão SD não foi encontrado - Verifique se o cartão está inserido corretamente.", MsgBoxStyle.Critical, "Apagar Registos")
                    RSComandAttempts = 1
                    Exit Sub
                ElseIf AuxStr.StartsWith("@WSSDFD@") Then
                    TotalFilesDeleted = TotalFilesDeleted + 1
                    If CheckBox1.Checked = True Then
                        If boMoreEvents = False Then
                            boMoreEvents = True
                            Button5.PerformClick()
                        ElseIf boMoreEvents = True Then
                            If MoreEventsCounter >= NumericUpDown1.Value Then
                                MsgBox("Dados Apagados com sucesso!" & vbNewLine & TotalFilesDeleted & " Ficheiros Foram Apagados.", MsgBoxStyle.Information, "Apagar Registos")
                                MoreEventsCounter = 1
                                boMoreEvents = False
                                Button2.Enabled = True
                                Button3.Enabled = True
                                Button1.Enabled = True
                                Button2.BackColor = Color.LightGreen
                                Button3.BackColor = Color.LightGreen
                            Else
                                Button5.PerformClick()
                            End If
                        End If
                    Else
                        MsgBox("Ficheiro Apagado com sucesso!", MsgBoxStyle.Information, "Apagar Registos")
                        Button2.Enabled = True
                        Button3.Enabled = True
                        Button1.Enabled = True
                        Button2.BackColor = Color.LightGreen
                        Button3.BackColor = Color.LightGreen
                    End If
                Else
                    If CheckBox1.Checked = True Then
                        If boMoreEvents = False Then
                            boMoreEvents = True
                            Button5.PerformClick()
                        ElseIf boMoreEvents = True Then
                            If MoreEventsCounter >= NumericUpDown1.Value Then
                                MsgBox("Dados Apagados com sucesso!" & vbNewLine & TotalFilesDeleted & " Ficheiros Foram Apagados.", MsgBoxStyle.Information, "Apagar Registos")
                                MoreEventsCounter = 1
                                boMoreEvents = False
                                Button2.Enabled = True
                                Button3.Enabled = True
                                Button1.Enabled = True
                                Button2.BackColor = Color.LightGreen
                                Button3.BackColor = Color.LightGreen
                            Else
                                Button5.PerformClick()
                            End If
                        End If
                    Else
                        MsgBox("Erro ao abrir o ficheiro " & Day & "/" & Month & "/" & Year & " - O ficheiro poderá não existir ou estar danificado.", MsgBoxStyle.Critical, "Apagar Registos")
                        RSComandAttempts = 1
                        Exit Sub
                    End If
                End If
            Else
                MsgBox(" O Sistema não está conectado ao Atmega.", MsgBoxStyle.Critical, "Apagar Registos")
            End If
        Catch ex As Exception
            MsgBox("Erro ao Executar o Download de Registos - Tente Novamente.", MsgBoxStyle.Critical, "Apagar Registos")
            RSComandAttempts = 1
        End Try

        RSComandAttempts = 1

    End Sub
End Class
