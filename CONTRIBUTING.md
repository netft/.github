# Cross-repository contributions

The organization has five runtime components, netft-docs, and this navigation/policy repository. Component-specific contribution and security instructions take precedence for their code. Shared user documentation lives at https://netft.dev.

Protocol/calibration/recovery changes start in netft-cpp. Each consumer maintainer verifies its exact SDK commit, inventory hash, license and private adaptation before release. CLI owns its bias/socket-retention adaptation; Python, ROS and Viewer own delivery, realtime and packaging boundaries respectively. Documentation maintainers verify source versions and candidate/released identities before regenerating references.

Release SDK fixes first, then consumers against the approved release commit, then version-pinned references and organization navigation. Keep repositories independently versioned. A coordinated change description must identify affected repositories, owners by component, source commits, necessary finite validation, compatibility effects and remaining platform acceptance. Use the common issue/PR templates where a repository does not supply its own.

Report source and product defects to the relevant repository as described in profile/README.md. Shared guide/reference issues go to netft-docs; navigation/policy issues go here. Consult the component compatibility table for exact support commitments. Do not infer production signing, deployment permissions or all-platform support from a single local build.
