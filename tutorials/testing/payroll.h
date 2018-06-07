#pragma once

/// Calculates the pay for a worker.
/// First 40 hours paid at `hourly_rate'
/// Next 5 hours paid at 1.5 * `hourly_rate'
/// Any more hours paid at 2 * `hourly_rate'
int payroll(int hourly_rate, int hours_worked);
