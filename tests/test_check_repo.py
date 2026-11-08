"""scripts/check_repo.py passes on the repository (the same check CI runs)."""
import check_repo


def test_repository_is_consistent(capsys):
    assert check_repo.main() == 0, capsys.readouterr().out
