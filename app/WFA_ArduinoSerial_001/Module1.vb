Imports System.IO

Module Module1

    Public Structure Arduino
        Public Day As String
        Public Month As String
        Public Year As String
        Public Hour As String
        Public Minute As String
        Public Temperature As String
    End Structure

    Public A_Arduino(10000000) As Arduino
    Public TotalArduinoLoaded As Integer
    Public StrEventsReceived As String
    Public Flg_LoadArduinoList As Boolean
    Public StrArduinoList As String
    Public DeviceSN As String
    Public DeviceMonth As String
    Public DeviceYear As String
    Public EventsDate As String
    Public TotalFilesDeleted As Integer

    Public Sub LoadArduinoEvents()

        Try
            Dim DataArray() As String

            DataArray = StrEventsReceived.Split("|")

            For Aux = 1 To DataArray.Length - 2 Step 6

                With A_Arduino(TotalArduinoLoaded)

                    .Day = DataArray(Aux)
                    .Month = DataArray(Aux + 1)
                    .Year = DataArray(Aux + 2)
                    .Hour = DataArray(Aux + 3)
                    .Minute = DataArray(Aux + 4)
                    .Temperature = DataArray(Aux + 5)

                    TotalArduinoLoaded += 1

                End With
            Next
            Flg_LoadArduinoList = True
        Catch ex As Exception
            MsgBox("Erro ao Registar Eventos Para Aplicação", MsgBoxStyle.Critical, "LoadArduinoEvents()")
            Flg_LoadArduinoList = False

        End Try

    End Sub

    Public Sub DisplayArduinoEvents()

        StrArduinoList &= "             " & "  Data" & "           " & "Hora" & "     " & " Temperatura" & vbNewLine & vbNewLine

        For Aux1 = 0 To TotalArduinoLoaded - 1

            StrArduinoList &= vbTab & A_Arduino(Aux1).Day & "/" &
                 A_Arduino(Aux1).Month & "/" &
                 A_Arduino(Aux1).Year & "       " &
                 A_Arduino(Aux1).Hour & ":" &
                 A_Arduino(Aux1).Minute & "         " &
                 A_Arduino(Aux1).Temperature & " ºC" & vbNewLine

        Next

    End Sub

    Public Sub SaveDataIntoTextFile(ByVal FileName As String)

        Dim Aux1 As Short
        Dim FilePointer As FileStream
        Dim AuxStr As String

        AuxStr = "   Data" & "       " & "Hora" & "   " & "Temperatura" & vbNewLine & vbNewLine

        FilePointer = New FileStream(FileName, FileMode.OpenOrCreate, FileAccess.Write)

        Dim StreamOutput As New StreamWriter(FilePointer)

        StreamOutput.BaseStream.Seek(0, SeekOrigin.Begin)


        For Aux1 = 0 To TotalArduinoLoaded - 1

            StreamOutput.Write(AuxStr & A_Arduino(Aux1).Day & "/" &
                               A_Arduino(Aux1).Month & "/" &
                               A_Arduino(Aux1).Year & "    " &
                               A_Arduino(Aux1).Hour & ":" &
                               A_Arduino(Aux1).Minute & "    " &
                               A_Arduino(Aux1).Temperature & " ºC" & vbNewLine)
            AuxStr = ""
        Next


        StreamOutput.Close()
        FilePointer.Close()

    End Sub

    Public Function SaveDataIntoExcelSheet(ByVal FileName As String) As Boolean

        Dim objExcel As Excel.Application, objWorkbook As Excel.Workbook
        Dim objSheet As Excel.Worksheet
        Dim strFileName As String
        Dim Aux1 As Short
        Dim Counter As Short
        Dim A_Aux(10000000) As String

        Try

            objExcel = CreateObject("Excel.Application")
            objExcel.Visible = True
            strFileName = CurDir() & "\SpreadSheet.xlsx"
            objWorkbook = objExcel.Workbooks.Add(strFileName)

            objSheet = objWorkbook.Sheets("Importar Registos")
            objSheet.Cells(1, 1) = TotalArduinoLoaded & " registos estão a ser importados..."

            objSheet = objWorkbook.Sheets("Registos")
            objSheet.Cells(2, 5) = DeviceSN
            objSheet.Cells(4, 5) = Now.Date & " " & Now.Hour & ":" & Now.Minute
            objSheet.Cells(5, 5) = TotalArduinoLoaded & " registos importados para a(s) Data(s) " & EventsDate
            objSheet.Cells(6, 5) = EventsDate

            Counter = 2

            For Aux1 = 0 To TotalArduinoLoaded - 1

                A_Aux(Aux1) = A_Arduino(Aux1).Month & "/" & A_Arduino(Aux1).Day & "/" & A_Arduino(Aux1).Year & " " & A_Arduino(Aux1).Hour & ":" & A_Arduino(Aux1).Minute & ":" & "00"

                objSheet.Cells(Counter, 1) = A_Aux(Aux1)
                objSheet.Cells(Counter, 2) = A_Arduino(Aux1).Hour & ":" & A_Arduino(Aux1).Minute & ":" & "00"
                objSheet.Cells(Counter, 3) = A_Arduino(Aux1).Temperature

                Counter += 1
            Next

            objSheet = objWorkbook.Sheets("Importar Registos")
            objExcel.DisplayAlerts = False
            objSheet.Delete()
            objWorkbook.SaveAs(FileName, Excel.XlFileFormat.xlWorkbookDefault)
            objWorkbook.Close(False)
            objExcel.Quit()

            Return True

        Catch ex As Exception
            MsgBox(ex.ToString, MsgBoxStyle.Exclamation, "Erro ao criar ficheiro Excel")
            MsgBox("Reference Path : " & strFileName)
            MsgBox("Selected Path : " & FileName)
            Return False

        End Try

    End Function


End Module
