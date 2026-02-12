import 'dart:io';
import 'package:flutter/material.dart';
import 'package:file_picker/file_picker.dart';
import 'package:excel/excel.dart';
import 'package:intl/intl.dart';

void main() {
  runApp(const AttendancePC());
}

class AttendancePC extends StatelessWidget {
  const AttendancePC({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: const HomePage(),
    );
  }
}

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  Excel? excel;
  Sheet? sheet;
  List<List<Data?>> rows = [];

  Future<void> loadExcel() async {
    final result = await FilePicker.platform.pickFiles(
      type: FileType.custom,
      allowedExtensions: ['xlsx'],
    );

    if (result != null) {
      final file = File(result.files.single.path!);
      final bytes = file.readAsBytesSync();
      excel = Excel.decodeBytes(bytes);
      sheet = excel!.tables.values.first;
      rows = sheet!.rows;
      setState(() {});
    }
  }

  void markAttendance(int rowIndex, int value) async {
    String today = DateFormat('dd-MM-yyyy').format(DateTime.now());
    int colIndex = rows[0].length;

    sheet!.cell(
      CellIndex.indexByColumnRow(
        columnIndex: colIndex,
        rowIndex: 0,
      ),
    ).value = today;

    sheet!.cell(
      CellIndex.indexByColumnRow(
        columnIndex: colIndex,
        rowIndex: rowIndex,
      ),
    ).value = value;

    final bytes = excel!.encode();
    final file = File('attendance.xlsx');
    await file.writeAsBytes(bytes!);

    ScaffoldMessenger.of(context)
        .showSnackBar(const SnackBar(content: Text("Saved")));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Attendance PC App'),
        actions: [
          IconButton(
            icon: const Icon(Icons.upload_file),
            onPressed: loadExcel,
          ),
        ],
      ),
      body: excel == null
          ? const Center(child: Text("Upload Excel File"))
          : ListView.builder(
              itemCount: rows.length - 1,
              itemBuilder: (context, index) {
                final row = rows[index + 1];

                return Card(
                  child: ListTile(
                    title: Text(row[1]?.value.toString() ?? ''),
                    subtitle:
                        Text("Application ID: ${row[0]?.value.toString()}"),
                    trailing: Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        ElevatedButton(
                          onPressed: () =>
                              markAttendance(index + 1, 1),
                          child: const Text("Present"),
                        ),
                        const SizedBox(width: 10),
                        ElevatedButton(
                          style: ElevatedButton.styleFrom(
                              backgroundColor: Colors.red),
                          onPressed: () =>
                              markAttendance(index + 1, 0),
                          child: const Text("Absent"),
                        ),
                      ],
                    ),
                  ),
                );
              },
            ),
    );
  }
}
