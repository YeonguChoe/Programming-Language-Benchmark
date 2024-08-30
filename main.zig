// Production compile command
// zig build --prefix-exe-dir .. -Doptimize=ReleaseFast --summary none

const std = @import("std");

// Factorial
fn factorial(num: u64) u64 {
    if (num == 0 or num == 1) {
        return 1;
    }

    var result: u64 = 1;

    for (2..num + 1) |i| {
        result *= i;
    }

    return result;
}

pub fn main() void {
    const input: u64 = 20;
    const iteration: u64 = 700;

    var count: u64 = 0;
    const lastValue = (iteration - 2) * (iteration - 2) * (iteration - 2) * (iteration - 2);

    // Start timer
    const start = std.time.nanoTimestamp();

    for (2..iteration) |_| {
        for (2..iteration) |_| {
            for (2..iteration) |_| {
                for (2..iteration) |_| {
                    _ = factorial(input);

                    count += 1;
                    if (count == lastValue) {
                        std.debug.print("==================================================\n", .{});
                        std.debug.print("Result count: {}\n", .{count});
                    }
                }
            }
        }
    }

    // End timer
    const end = std.time.nanoTimestamp();

    const elapsed_nanos = end - start;
    const float_conversion = @as(f64, @floatFromInt(elapsed_nanos));
    const elapsed_time: f64 = float_conversion / 1_000_000_000.0;

    std.debug.print("Expected count: {}\n", .{lastValue});
    std.debug.print("==================================================\n", .{});

    std.debug.print("Zig Runtime: {d:1.8} seconds\n", .{elapsed_time});
    std.debug.print("==================================================\n", .{});
}
