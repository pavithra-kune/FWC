module _7447(

    output A,
    output B,
    output C,
    output D

);

wire X;
wire Z;
wire F;

// Given in the question
assign X = 1'b1;

// Change this to 1'b1 if you want to test the other case
assign Z = 1'b0;

// Simplified expression when X = 1
assign F = ~Z;

// BCD output to 7447
assign A = F;
assign B = 1'b0;
assign C = 1'b0;
assign D = 1'b0;

endmodule
