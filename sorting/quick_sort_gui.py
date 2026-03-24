import tkinter as tk
from tkinter import ttk
import copy

CODE_LINES = [
    "def partition(a, start, end):",
    "    pivot = a[start]",
    "    i = start + 1",
    "    j = end",
    "    while i <= j:",
    "        while i <= end and a[i] <= pivot:",
    "            i += 1",
    "        while a[j] > pivot:",
    "            j -= 1",
    "        if i < j:",
    "            swap(a, i, j)",
    "    swap(a, start, j)",
    "    return j",
    "def quicksort(a, start, end):",
    "    if start < end:",
    "        p = partition(a, start, end)",
    "        quicksort(a, start, p - 1)",
    "        quicksort(a, p + 1, end)",
]


class QuickSortTracer:
    def __init__(self, array):
        self.array = array
        self.states = []

    def record(self, line, a, i=-1, j=-1, pivot=-1, msg=""):
        self.states.append({
            "line": line,
            "array": copy.deepcopy(a),
            "i": i,
            "j": j,
            "pivot": pivot,
            "msg": msg,
        })

    def swap(self, a, x, y):
        a[x], a[y] = a[y], a[x]

    def partition(self, a, start, end):
        self.record(2, a, i=start + 1, j=end, pivot=start, msg=f"partition({start},{end}) start")
        pivot_val = a[start]
        i = start + 1
        j = end
        self.record(3, a, i=i, j=j, pivot=start, msg="pivot selected")

        while i <= j:
            self.record(5, a, i=i, j=j, pivot=start, msg="compare i")
            while i <= end and a[i] <= pivot_val:
                i += 1
                self.record(6, a, i=i, j=j, pivot=start, msg="move i")

            self.record(8, a, i=i, j=j, pivot=start, msg="compare j")
            while a[j] > pivot_val:
                j -= 1
                self.record(9, a, i=i, j=j, pivot=start, msg="move j")

            if i < j:
                self.record(10, a, i=i, j=j, pivot=start, msg=f"swap i={i}, j={j}")
                self.swap(a, i, j)
                self.record(11, a, i=i, j=j, pivot=start, msg="after swap")

        self.record(12, a, i=i, j=j, pivot=start, msg="swap pivot")
        self.swap(a, start, j)
        self.record(13, a, i=i, j=j, pivot=j, msg="pivot placed")
        return j

    def quicksort(self, a, start, end):
        self.record(15, a, i=start, j=end, pivot=-1, msg=f"quicksort({start},{end}) entry")
        if start < end:
            self.record(16, a, i=start, j=end, pivot=-1, msg="partition call")
            p = self.partition(a, start, end)
            self.record(17, a, i=p, j=p, pivot=p, msg=f"pivot index {p}")
            self.quicksort(a, start, p - 1)
            self.quicksort(a, p + 1, end)
        else:
            self.record(18, a, i=start, j=end, pivot=-1, msg="sorted segment")

    def run(self):
        self.quicksort(self.array, 0, len(self.array) - 1)
        self.record(-1, self.array, msg="done")


class QuickSortGUI(tk.Tk):
    def __init__(self, tracer):
        super().__init__()
        self.title("QuickSort GUI Animation")
        self.geometry("900x500")
        self.resizable(False, False)

        self.tracer = tracer
        self.state_index = 0

        self.setup_widgets()
        self.draw_state()

    def setup_widgets(self):
        left = ttk.Frame(self)
        left.pack(side="left", fill="y", padx=5, pady=5)

        self.code_text = tk.Text(left, width=36, height=24, font=("Courier", 11))
        self.code_text.pack(padx=4, pady=4)
        self.code_text.insert("1.0", "\n".join(CODE_LINES))
        self.code_text.config(state="disabled")

        right = ttk.Frame(self)
        right.pack(side="left", fill="both", expand=True, padx=5, pady=5)

        self.canvas = tk.Canvas(right, width=520, height=360, bg="#FFFFFF")
        self.canvas.pack(pady=8)

        self.message = ttk.Label(right, text="", font=("Arial", 11), foreground="#333")
        self.message.pack(pady=2)

        controls = ttk.Frame(right)
        controls.pack(pady=8)

        self.prev_btn = ttk.Button(controls, text="Previous", command=self.prev_state)
        self.prev_btn.pack(side="left", padx=5)

        self.next_btn = ttk.Button(controls, text="Next", command=self.next_state)
        self.next_btn.pack(side="left", padx=5)

        self.play_btn = ttk.Button(controls, text="Play", command=self.play_pause)
        self.play_btn.pack(side="left", padx=5)

        self.auto_play = False

    def draw_state(self):
        state = self.tracer.states[self.state_index]

        self.code_text.config(state="normal")
        self.code_text.tag_remove("highlight", "1.0", "end")
        self.code_text.tag_configure("highlight", background="#ffff99")
        if state["line"] > 0:
            self.code_text.tag_add("highlight", f"{state['line']}.0", f"{state['line']}.end")
        self.code_text.config(state="disabled")

        self.canvas.delete("all")
        arr = state["array"]
        n = len(arr)
        bar_width = 500 / n
        max_value = max(arr)

        for idx, val in enumerate(arr):
            x0 = 10 + idx * bar_width
            y0 = 340
            x1 = x0 + bar_width - 4
            y1 = y0 - (val / max_value) * 300 if max_value > 0 else y0
            color = "skyblue"
            if idx == state["pivot"]:
                color = "orange"
            if idx == state["i"]:
                color = "blue"
            if idx == state["j"]:
                color = "red"
            if idx == state["i"] and idx == state["j"]:
                color = "purple"

            self.canvas.create_rectangle(x0, y0, x1, y1, fill=color, outline="#333")
            self.canvas.create_text((x0 + x1) / 2, y0 + 12, text=str(val), font=("Arial", 10))
            self.canvas.create_text((x0 + x1) / 2, y0 + 28, text=str(idx), font=("Arial", 8))

        self.message.config(text=f"Step {self.state_index + 1}/{len(self.tracer.states)}: {state['msg']}")

        self.prev_btn.config(state="normal" if self.state_index > 0 else "disabled")
        self.next_btn.config(state="normal" if self.state_index < len(self.tracer.states) - 1 else "disabled")

    def next_state(self):
        if self.state_index < len(self.tracer.states) - 1:
            self.state_index += 1
            self.draw_state()

    def prev_state(self):
        if self.state_index > 0:
            self.state_index -= 1
            self.draw_state()

    def play_pause(self):
        self.auto_play = not self.auto_play
        self.play_btn.config(text="Pause" if self.auto_play else "Play")
        if self.auto_play:
            self.after(450, self.auto_advance)

    def auto_advance(self):
        if self.auto_play and self.state_index < len(self.tracer.states) - 1:
            self.state_index += 1
            self.draw_state()
            self.after(450, self.auto_advance)
        else:
            self.auto_play = False
            self.play_btn.config(text="Play")


if __name__ == "__main__":
    initial_array = [10, 7, 8, 9, 1, 5]
    tracer = QuickSortTracer(initial_array)
    tracer.run()
    app = QuickSortGUI(tracer)
    app.mainloop()
