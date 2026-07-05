module _7seg(

    output reg seg_a,
    output reg seg_b,
    output reg seg_c,
    output reg seg_d,
    output reg seg_e,
    output reg seg_f,
    output reg seg_g

);

wire X;
wire Y;
wire Z;
wire F;

assign X = 1'b1;   // Given in the question
assign Y = 1'b0;   // Doesn't affect the final result
assign Z = 1'b0;   // Change to 1'b1 if you want to test the other case

// Final simplified output
assign F = ~Z;

always @(*) begin

    if (F == 1'b1)
    begin
        // Display 1 (Common Anode)
        seg_a = 1'b1;
        seg_b = 1'b0;
        seg_c = 1'b0;
        seg_d = 1'b1;
        seg_e = 1'b1;
        seg_f = 1'b1;
        seg_g = 1'b1;
    end

    else
    begin
        // Display 0
        seg_a = 1'b0;
        seg_b = 1'b0;
        seg_c = 1'b0;
        seg_d = 1'b0;
        seg_e = 1'b0;
        seg_f = 1'b0;
        seg_g = 1'b1;
    end

end

endmodule
