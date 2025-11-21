
module Decoder2to4(
    input A, B, En;
    output D0, D1, D2, D3;
);

    wire Abar, Bbar;

    not (Abar, A);
    not (Bbar, B);

    and (D0, Abar, Bbar, En);
    and (D1, A, Bbar, En);
    and (D2, Abar, B, En);
    and (D3, A, B, En);
endmodule