# Synthetic fault corpus

Schema 1 contains synthetic inputs only. The three hex files are exact RDT bytes (36/35/37 bytes), including signed count extremes and sequence rollover. XML fixtures distinguish unsafe finite positive scales from valid small scales. `manifest.json` defines expected transport/calibration semantics and separate consumer-level queue/file failures. No private hardware capture is included.

All four downstream consumers carry the same verified SDK source, so its protocol/discovery regressions define decoding expectations. Existing relevant cases: SDK `Protocol.DecodesTwoComplementAxisBoundaries`, `Protocol.RejectsNullAndMalformedRecords`, `Calibration.RejectsScalesThatOverflowRawRange`, `RdtSequence.HandlesFirstContiguousRolloverGapsAndOrdering`; Python integration stream/recovery and bounded queue tests; CLI OutputFile/Recorder cases; ROS SI-overflow fault; Viewer Recorder pause/overflow/finalization cases. File-failure entries describe injected conditions, not network byte strings.

Use these inputs for reproductions or future consumer regressions. This corpus does not force repositories to download another repository at test time and does not replace their fake sensors. `tools/performance/` probes remain opt-in. Keep additions minimal and map every expected behavior to a component's observable contract.
