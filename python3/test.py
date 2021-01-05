import pkg_resources
requirements_file = "requirements.txt"
with open(requirements_file) as fd:
  for pkg in fd:
    pkg = pkg.strip()
    pkg_resources.require(pkg)
    print("Has {}".format(pkg))
